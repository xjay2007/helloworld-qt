#include "canvasdialog.h"
#include "ui_canvasdialog.h"
#include <QPainter>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPushButton>

CanvasDialog::CanvasDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CanvasDialog)
{
    ui->setupUi(this);

    resize(400, 300);
    clear();

    connect(ui->zoomInButton, SIGNAL(clicked()), this, SLOT(zoomIn()));
    connect(ui->zoomOutButton, SIGNAL(clicked()), this, SLOT(zoomOut()));
    connect(ui->clearButton, SIGNAL(clicked()), this, SLOT(onClear()));
    connect(ui->freeRadioButton, SIGNAL(clicked()), this, SLOT(selectFree()));
    connect(ui->rectangleRadioButton, SIGNAL(clicked()), this, SLOT(selectRectangle()));
}

CanvasDialog::~CanvasDialog()
{
    delete ui;
}

void CanvasDialog::clear()
{
    pix = QPixmap(300, 300);
    pix.fill(Qt::white);
}

void CanvasDialog::paintEvent(QPaintEvent *)
{
    switch (drawType) {
    case Free: {

        QPainter pp(&pix);
        pp.drawLine(lastPoint/zoomScale, endPoint/zoomScale);
        lastPoint = endPoint;

        QPainter painter(this);
        painter.scale(zoomScale, zoomScale);
        painter.drawPixmap(0, 0, pix);
        break;
    }
    case Rectangle: {
        int x, y, w, h;
        x = lastPoint.x();
        y = lastPoint.y();
        w = endPoint.x()-x;
        h = endPoint.y()-y;

        if (isDrawing) {
            tempPix = pix;
            QPainter pp(&tempPix);
            pp.drawRect(x/zoomScale, y/zoomScale, w/zoomScale, h/zoomScale);

            QPainter painter(this);
            painter.scale(zoomScale, zoomScale);
            painter.drawPixmap(0, 0, tempPix);
        } else {
            QPainter pp(&pix);
            pp.drawRect(x/zoomScale, y/zoomScale, w/zoomScale, h/zoomScale);

            QPainter painter(this);
            painter.scale(zoomScale, zoomScale);
            painter.drawPixmap(0, 0, pix);
        }

        break;
    }
    default:
        break;
    }
}

void CanvasDialog::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton) {
        lastPoint = e->pos();
        endPoint = e->pos();
        isDrawing = true;
        update();
    }
}

void CanvasDialog::mouseMoveEvent(QMouseEvent *e)
{
    if (e->buttons() & Qt::LeftButton) {
        endPoint = e->pos();
        update();
    }
}

void CanvasDialog::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton) {
//        lastPoint = e->pos();
        endPoint = e->pos();
        isDrawing = false;
        update();
    }
}

void CanvasDialog::zoomIn()
{
    zoomScale += 1.0;
    zoomScale = std::min(zoomScale, 8.0);
    update();
}

void CanvasDialog::zoomOut()
{
    zoomScale -= 1.0;
    zoomScale = std::max(zoomScale, 1.0);
    update();
}

void CanvasDialog::onClear()
{
    clear();
    update();
}

void CanvasDialog::selectFree()
{
    drawType = Free;
    update();
}

void CanvasDialog::selectRectangle()
{
    drawType = Rectangle;
    update();
}

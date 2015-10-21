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
    pix = QPixmap(300, 300);
    pix.fill(Qt::white);
}

CanvasDialog::~CanvasDialog()
{
    delete ui;
}

void CanvasDialog::paintEvent(QPaintEvent *)
{
    if (scale != 1) {
        QPixmap copyPix(pix.size()*scale);
        QPainter p(&copyPix);
        p.scale(scale, scale);
        p.drawPixmap(0, 0, pix);
        pix = copyPix;
        scale = 1;
    }
    QPainter pp(&pix);
    pp.scale(scale, scale);
    pp.drawLine(lastPoint/scale, endPoint/scale);
    lastPoint = endPoint;
    QPainter painter(this);
    painter.drawPixmap(0, 0, pix);
}

void CanvasDialog::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton) {
        endPoint = e->pos();
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
        endPoint = e->pos();
        update();
    }
}

void CanvasDialog::zoomIn()
{
    scale *= 2;
    scale = std::min(scale, 4.0);
    update();
}

void CanvasDialog::zoomOut()
{
    scale /= 2;
    scale = std::max(scale, 1.0);
}

void CanvasDialog::on_pushButton_clicked()
{
    zoomIn();
}

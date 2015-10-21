#include "painterwindow.h"
#include "ui_painterwindow.h"
#include <QPaintEvent>
#include <QPainter>
#include <QFileDialog>
#include "canvasdialog.h"

PainterWindow::PainterWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PainterWindow)
{
    ui->setupUi(this);
}

PainterWindow::~PainterWindow()
{
    delete ui;
}

void PainterWindow::paintEvent(QPaintEvent *)
{
    auto painter = XPainterFactory::createPainter(paintType);
    painter->paint(this);
    X_SAFE_DELETE(painter);
}

void PainterWindow::on_pushButton_clicked()
{
    paintType = Type::Simple;
    repaint();
}

void PainterWindow::on_pushButton_2_clicked()
{
    paintType = Type::Gradient;
    repaint();
}

void PainterWindow::on_pushButton_3_clicked()
{
    paintType = Type::Text;
    repaint();
}

void PainterWindow::on_pushButton_4_clicked()
{
    paintType = Type::Path;
    repaint();
}

void PainterWindow::on_pushButton_5_clicked()
{
    paintType = Type::Image;
    repaint();
}

void PainterWindow::on_pushButton_6_clicked()
{
    if (nullptr == canvasDlg) {
        canvasDlg = new CanvasDialog(this);
    }
    canvasDlg->show();
}


XPainter *XPainterFactory::createPainter(Type type)
{
    switch (type) {
    case Type::Simple:
        return new XPainterSimple();
    case Type::Gradient:
        return new XPainterGradient();
    case Type::Text:
        return new XPainterText();
    case Type::Path:
        return new XPainterPath();
    case Type::Image:
        return new XPainterImage();
    default:
        break;
    }
    return new XPainter(type);
}


void XPainterSimple::paint(QWidget *widget)
{
    QPainter painter(widget);
    QPen pen(Qt::DotLine);
    QBrush brush(Qt::blue);
    brush.setStyle(Qt::HorPattern);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(50, 50, 200, 100);

    QRectF rect(10, 20, 80, 60);
    int startAngle = 30 * 16;
    int spanAngle = 120*16;
    painter.drawArc(rect, startAngle, spanAngle);
}


void XPainterGradient::paint(QWidget *widget)
{
    QPainter painter(widget);

    // linear gradient
    QLinearGradient linearGradient(QPointF(40, 190), QPointF(70, 190));
    linearGradient.setColorAt(0, Qt::yellow);
    linearGradient.setColorAt(0.5, Qt::red);
    linearGradient.setColorAt(1, Qt::green);

    linearGradient.setSpread(QGradient::PadSpread);

    painter.setBrush(linearGradient);
    painter.drawRect(10, 20, 90, 40);

    // GradientRadial:
    QRadialGradient radial(QPointF(100, 190), 50, QPointF(275, 200));
    radial.setColorAt(0, QColor(255, 255, 100, 150));
    radial.setColorAt(1, QColor(0, 0, 0, 50));

    painter.setBrush(radial);
    painter.drawEllipse(QPointF(100, 190), 50, 50);

    // GradientConical
    QConicalGradient conical(QPointF(250, 190), 60);
    conical.setColorAt(0.2, Qt::cyan);
    conical.setColorAt(0.9, Qt::black);

    painter.setBrush(conical);
    painter.drawEllipse(QPointF(250, 190), 50, 50);
}


void XPainterText::paint(QWidget *widget)
{
    QPainter painter(widget);

    painter.drawText(100, 100, "hello 1");

    // positino
    QRectF rect(20, 20, 300, 200);
    painter.drawRect(rect);
    painter.setPen(QColor(Qt::red));
    painter.drawText(rect, Qt::AlignHCenter, "hello 2");

    // Font
    QFont font("宋体", 15, QFont::Bold, true);
    font.setUnderline(true);
    font.setOverline(true);
    font.setCapitalization(QFont::SmallCaps);
    font.setLetterSpacing(QFont::AbsoluteSpacing, 10);
    painter.setFont(font);
    painter.setPen(Qt::green);
    painter.drawText(120, 80, "hello 3");
    painter.translate(50, 50);
    painter.rotate(90);
    painter.drawText(0, 0, "hello 3 2");
}

void XPainterPath::paint(QWidget *widget)
{
    QPainter painter(widget);

    QPainterPath path;
    path.addEllipse(100, 100, 50, 50);
    path.lineTo(200, 200);
    painter.setPen(Qt::blue);
    painter.setBrush(Qt::red);
    painter.drawPath(path);

    QPainterPath path2;
    path2.addPath(path);
    path2.translate(100, 0);
    painter.drawPath(path2);
}


void XPainterImage::paint(QWidget *widget)
{
//    if (!isFileLoaded) {
//        auto filename = QFileDialog::getOpenFileName(widget, "Open File", "", "Images (*.png *.jpg)");
//        if (!filename.isEmpty()) {
//            this->filename = filename;
//            isFileLoaded = true;
//        }
//    }
//    if (isFileLoaded) {
        QPainter painter(widget);

        QPixmap pix;
        pix.load(filename);
        auto w = pix.width();
        auto h = pix.height();
        painter.drawPixmap(0, 0, w, h, pix);

        painter.translate(50, 0);
        painter.drawPixmap(0, 0, w*2, h, pix);

        pix = pix.scaled(w*2, h*2, Qt::KeepAspectRatio);
        painter.drawPixmap(100, 0, pix);

        painter.translate(w/2, h/2);
        painter.rotate(90);
        painter.translate(-w/2, -h/2);
        painter.drawPixmap(50, 50, pix);

        painter.shear(0.5, 0);
        painter.drawPixmap(100, 50, pix);
//    }
}

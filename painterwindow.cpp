#include "painterwindow.h"
#include "ui_painterwindow.h"
#include <QPaintEvent>
#include <QPainter>

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
//    QPainter painter(this);
//    QPen pen(Qt::PenStyle::DotLine);
//    QBrush brush(Qt::GlobalColor::blue);
//    brush.setStyle(Qt::BrushStyle::HorPattern);
//    painter.setPen(pen);
//    painter.setBrush(brush);
//    painter.drawRect(50, 50, 200, 100);

    QRectF rect(10, 20, 80, 60);
    int startAngle = 30 * 16;
    int spanAngle = 120*16;
    QPainter painter(this);
    painter.drawArc(rect, startAngle, spanAngle);
}



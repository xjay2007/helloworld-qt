#include "touchwidget.h"
#include "ui_touchwidget.h"

#include <QMouseEvent>
#include <QKeyEvent>

TouchWidget::TouchWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TouchWidget)
{
    ui->setupUi(this);
}

TouchWidget::~TouchWidget()
{
    delete ui;
}

void TouchWidget::mousePressEvent(QMouseEvent *e)
{
    auto text = tr("(%1, %2)").arg(e->x()).arg(e->y());
    ui->pushButton->setText(text);
}

void TouchWidget::keyPressEvent(QKeyEvent *e)
{
    auto btn = ui->pushButton;
    int x = btn->x();
    int y = btn->y();
    switch (e->key()) {
    case Qt::Key::Key_W: btn->move(x, y-10); break;
    case Qt::Key::Key_S: btn->move(x, y+10); break;
    case Qt::Key::Key_A: btn->move(x-10, y); break;
    case Qt::Key::Key_D: btn->move(x+10, y); break;
    default:
        break;
    }
}

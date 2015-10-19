#ifndef TOUCHWIDGET_H
#define TOUCHWIDGET_H

#include <QWidget>


class QMouseEvent;
class QKeyEvent;

namespace Ui {
class TouchWidget;
}

class TouchWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TouchWidget(QWidget *parent = 0);
    ~TouchWidget();

protected:
    void mousePressEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent *e);
private:
    Ui::TouchWidget *ui;
};

#endif // TOUCHWIDGET_H

#ifndef TIMERWIDGET_H
#define TIMERWIDGET_H

#include <QWidget>


class QTimerEvent;

namespace Ui {
class TimerWidget;
}

class TimerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TimerWidget(QWidget *parent = 0);
    ~TimerWidget();

protected:
    void timerEvent(QTimerEvent *e);

private slots:
    void timerUpdate();
private:
    Ui::TimerWidget *ui;

    int id1, id2, id3;
};

#endif // TIMERWIDGET_H

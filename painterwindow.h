#ifndef PAINTERWINDOW_H
#define PAINTERWINDOW_H

#include <QMainWindow>

class QPaintEvent;

namespace Ui {
class PainterWindow;
}

class PainterWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PainterWindow(QWidget *parent = 0);
    ~PainterWindow();

protected:
    void paintEvent(QPaintEvent *e);
private:
    Ui::PainterWindow *ui;
};

#endif // PAINTERWINDOW_H

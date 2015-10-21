#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>

namespace Ui {
class MenuWindow;
}

class MainWindow;
class TouchWidget;
class TimerWidget;
class PainterWindow;
class MyView;

class MenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = 0);
    ~MenuWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MenuWindow *ui;

    MainWindow *textEditor = nullptr;
    TouchWidget *touchEventWidget = nullptr;
    TimerWidget *timerWidget = nullptr;
    PainterWindow *painterWindow = nullptr;
    MyView *myView = nullptr;
};

#endif // MENUWINDOW_H

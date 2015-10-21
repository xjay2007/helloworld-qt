#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "mainwindow.h"
#include "touchwidget.h"
#include "timerwidget.h"
#include "painterwindow.h"
#include "myview.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

MenuWindow::MenuWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
}

MenuWindow::~MenuWindow()
{
    delete ui;
    X_SAFE_DELETE(textEditor);
    X_SAFE_DELETE(touchEventWidget);
    X_SAFE_DELETE(timerWidget);
    X_SAFE_DELETE(painterWindow);
}

void MenuWindow::on_pushButton_clicked()
{
    if (nullptr == textEditor) {
        textEditor = new MainWindow(this);
    }
    textEditor->show();
    textEditor->activateWindow();
}

void MenuWindow::on_pushButton_2_clicked()
{
    if (nullptr == touchEventWidget) {
        touchEventWidget = new TouchWidget();
    }
    touchEventWidget->show();
    touchEventWidget->activateWindow();
}

void MenuWindow::on_pushButton_3_clicked()
{
    if (nullptr == timerWidget) {
        timerWidget = new TimerWidget();
    }
    timerWidget->show();
    timerWidget->activateWindow();
}

void MenuWindow::on_pushButton_4_clicked()
{
    if (nullptr == painterWindow) {
        painterWindow = new PainterWindow(this);
    }
    painterWindow->show();
    painterWindow->activateWindow();
}

void MenuWindow::on_pushButton_5_clicked()
{
    if (nullptr == myView) {
        myView = new MyView;
    }
    myView->show();
}

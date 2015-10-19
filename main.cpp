#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <qfont.h>
#include <QVBoxLayout>
#include "logindialog.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());

    MainWindow w;
    w.show();
    return a.exec();
//    LoginDialog dlg;
//    if (dlg.exec() == QDialog::Accepted) {
//        w.show();
//        return a.exec();
//    } else {
//        return 0;
//    }
}

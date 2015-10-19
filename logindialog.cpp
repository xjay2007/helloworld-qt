#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_cancelButton_clicked()
{

}

void LoginDialog::on_loginButton_clicked()
{
    if (ui->usrLineEdit->text().trimmed() == "xj"
            && ui->pwdLineEdit->text() == "123") {
        accept();
    } else {
        QMessageBox::warning(this, "Warning", "error", QMessageBox::Yes);
        ui->usrLineEdit->clear();
        ui->pwdLineEdit->clear();
        ui->usrLineEdit->setFocus();
    }
}

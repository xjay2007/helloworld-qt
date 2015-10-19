#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdialog.h>
#include <qaction.h>
#include <qmessagebox.h>
#include <qfiledialog.h>
#include <qfile.h>
#include <qtextstream.h>
#include <QCloseEvent>
#include <QLineEdit>
#include <QDialog>
#include <QPushButton>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    isUntitled(true)
{
    ui->setupUi(this);

    setCurFile(tr("untitled.txt"));

    findDlg = new QDialog(this);
    findDlg->setWindowTitle(tr("Find"));
    findLineEdit = new QLineEdit(findDlg);
    auto btn = new QPushButton(tr("Find next"), findDlg);
    auto layout = new QVBoxLayout(findDlg);
    layout->addWidget(findLineEdit);
    layout->addWidget(btn);
    connect(btn, SIGNAL(clicked()), this, SLOT(showFindText()));

//    ui->statusBar->showMessage(tr("Welcome!"), 2000);
    statusLabel = new QLabel;
    statusLabel->setMinimumSize(150, 20);
    statusLabel->setFrameShape(QFrame::Shape::WinPanel);
    statusLabel->setFrameShadow(QFrame::Shadow::Sunken);
    ui->statusBar->addWidget(statusLabel);
    statusLabel->setText(tr("Welcome!"));

    auto permanent = new QLabel(this);
    permanent->setFrameStyle(QFrame::Shape::Box | QFrame::Shadow::Sunken);
    permanent->setText(tr("<a href=\"http://www.163.com\">netease</a>"));
    permanent->setTextFormat(Qt::TextFormat::RichText);
    permanent->setOpenExternalLinks(true);
    ui->statusBar->addPermanentWidget(permanent);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newFile() {
    if (maybeSave()) {
        isUntitled = true;
        setCurFile(tr("untitled.txt"));
        ui->textEdit->clear();
        ui->textEdit->setVisible(true);
    }
}
bool MainWindow::maybeSave() {
    if (ui->textEdit->document()->isModified()) {
        QMessageBox box;
        box.setWindowTitle(tr("Warning"));
        box.setIcon(QMessageBox::Icon::Warning);
        box.setText(curFile + tr(" is not saved, save?"));
        auto yesBtn = box.addButton(tr("&Yes"), QMessageBox::ButtonRole::YesRole);
        box.addButton(tr("&No"), QMessageBox::ButtonRole::NoRole);
        auto noBtn = box.addButton(tr("&Cancel"), QMessageBox::RejectRole);
        box.exec();
        if (box.clickedButton() == (QAbstractButton *)yesBtn) {
            return save();
        } else if (box.clickedButton() == (QAbstractButton *)noBtn) {
            return false;
        }
    }
    return true;
}
bool MainWindow::save() {
    if (isUntitled) {
        return saveAs();
    } else {
        return saveFile(curFile);
    }
}
bool MainWindow::saveAs() {
    QString filename = QFileDialog::getSaveFileName(this, tr("Save As"), curFile);
    if (filename.isEmpty()) return false;
    return saveFile(filename);
}
bool MainWindow::saveFile(const QString &filename) {
    QFile file(filename);

    if (!file.open(QFile::OpenModeFlag::WriteOnly | QFile::OpenModeFlag::Text)) {
        QMessageBox::warning(this, tr("Text Editor"), tr("Unabled to write to file %1: /n %2").arg(filename).arg(file.errorString()));
        return false;
    }

    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::CursorShape::WaitCursor);
    out << ui->textEdit->toPlainText();
    QApplication::restoreOverrideCursor();

    isUntitled = false;

    auto curFile = QFileInfo(filename).canonicalFilePath();
    setCurFile(curFile);
    return true;
}

bool MainWindow::loadFile(const QString &filename) {
    QFile file(filename);
    if (!file.open(QFile::OpenModeFlag::ReadOnly | QFile::OpenModeFlag::Text)) {
        QMessageBox::warning(this, tr("Text Editor"), tr("Unabled to load file %1:\n%2").arg(filename).arg(file.errorString()));
        return false;
    }
    QTextStream in(&file);
    QApplication::setOverrideCursor(Qt::CursorShape::WaitCursor);
    ui->textEdit->setPlainText(in.readAll());
    QApplication::restoreOverrideCursor();

    auto curFile = QFileInfo(filename).canonicalFilePath();
    setCurFile(curFile);
    return true;
}

void MainWindow::setCurFile(const QString& filename) {
    if (filename == curFile) return;
    curFile = filename;
    setWindowTitle(curFile);
}

void MainWindow::on_actionNew_N_triggered()
{
    newFile();
}

void MainWindow::on_actionSave_S_triggered()
{
    save();
}

void MainWindow::on_actionSaveAs_triggered()
{
    saveAs();
}

void MainWindow::on_actionOpen_O_triggered()
{
    if (maybeSave()) {
        auto filename = QFileDialog::getOpenFileName(this);

        if (!filename.isEmpty()) {
            loadFile(filename);
            ui->textEdit->setVisible(true);
        }
    }
}

void MainWindow::on_actionClose_W_triggered()
{
    if (maybeSave()) {
        ui->textEdit->setVisible(false);
    }
}

void MainWindow::on_actionUndo_U_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionCut_X_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionCopy_C_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPast_V_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionQuit_Q_triggered()
{
    on_actionClose_W_triggered();
    qApp->quit();
}

void MainWindow::on_actionFind_F_triggered()
{
    findDlg->show();
}

void MainWindow::closeEvent(QCloseEvent *event) {
    if (maybeSave()) {
        event->accept();
    } else {
        event->ignore();
    }
}

void MainWindow::showFindText() {
    auto str = findLineEdit->text();
    auto found = ui->textEdit->find(str, QTextDocument::FindFlag::FindBackward);
    if (!found) {
        QMessageBox::warning(this, tr("Find"), tr("Can't find %1").arg(str));
    }
}

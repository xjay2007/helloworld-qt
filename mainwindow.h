#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QCloseEvent;
class QLineEdit;
class QDialog;
class QLabel;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void newFile();
    bool maybeSave();
    bool save();
    bool saveAs();
    bool saveFile(const QString &filename);

    bool loadFile(const QString &filename);

private:
    void setCurFile(const QString& filename);

private slots:
    void on_actionNew_N_triggered();

    void on_actionSave_S_triggered();

    void on_actionSaveAs_triggered();

    void on_actionOpen_O_triggered();

    void on_actionClose_W_triggered();

    void on_actionUndo_U_triggered();

    void on_actionCut_X_triggered();

    void on_actionCopy_C_triggered();

    void on_actionPast_V_triggered();

    void on_actionQuit_Q_triggered();

    void on_actionFind_F_triggered();

private slots:
    void showFindText();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;

    bool isUntitled;
    QString curFile;

    QLineEdit *findLineEdit;
    QDialog *findDlg;

    QLabel *statusLabel;
};

#endif // MAINWINDOW_H

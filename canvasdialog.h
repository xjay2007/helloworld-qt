#ifndef CANVASDIALOG_H
#define CANVASDIALOG_H

#include <QDialog>

class QMouseEvent;

namespace Ui {
class CanvasDialog;
}

class CanvasDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CanvasDialog(QWidget *parent = 0);
    ~CanvasDialog();

protected:
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

private slots:
    void zoomIn();
    void zoomOut();

    void on_pushButton_clicked();

private:
    Ui::CanvasDialog *ui;

    qreal scale = 1.0;

    QPixmap pix;
    QPoint lastPoint;
    QPoint endPoint;
};

#endif // CANVASDIALOG_H

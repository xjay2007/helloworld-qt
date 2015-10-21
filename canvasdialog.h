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
    enum DrawType {
        Free,
        Rectangle,
    };

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

    void onClear();

    void selectFree();
    void selectRectangle();

private:
    void clear();
private:
    Ui::CanvasDialog *ui;

    qreal zoomScale = 1.0;

    DrawType drawType = Free;

    QPixmap pix;
    QPoint lastPoint;
    QPoint endPoint;

    QPixmap tempPix;
    bool isDrawing = false;
};

#endif // CANVASDIALOG_H

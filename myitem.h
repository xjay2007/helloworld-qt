#ifndef MYITEM_H
#define MYITEM_H
#include <QGraphicsItem>

class QKeyEvent;

class MyItem : public QGraphicsItem
{
public:
    MyItem();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *e);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *e);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *e);

protected:
    void keyPressEvent(QKeyEvent *e);
private:
    QColor color = QColor(qrand()%256, qrand()%256, qrand()%256);
};

#endif // MYITEM_H

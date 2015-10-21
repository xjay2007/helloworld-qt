#ifndef RECTITEM_H
#define RECTITEM_H

#include <QGraphicsItem>

class QGraphicsSceneDragDropEvent;

class RectItem : public QGraphicsItem
{
public:
    RectItem();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void dragEnterEvent(QGraphicsSceneDragDropEvent *e);
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *e);
    void dropEvent(QGraphicsSceneDragDropEvent *e);

private:
    QColor color = QColor(Qt::lightGray);
    bool dragOver;
};

#endif // RECTITEM_H

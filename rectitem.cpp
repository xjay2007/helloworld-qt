#include "rectitem.h"
#include <QPainter>
#include <QGraphicsSceneDragDropEvent>

RectItem::RectItem()
{
    setAcceptDrops(true);
}

QRectF RectItem::boundingRect() const
{
    return QRectF(0, 0, 50, 50);
}

void RectItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setBrush(dragOver ? color.light(130) : color);
    painter->drawRect(0, 0, 50, 50);
}

void RectItem::dragEnterEvent(QGraphicsSceneDragDropEvent *e)
{

}

void RectItem::dragLeaveEvent(QGraphicsSceneDragDropEvent *e)
{

}

void RectItem::dropEvent(QGraphicsSceneDragDropEvent *e)
{

}


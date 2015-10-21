#include "rectitem.h"
#include <QPainter>
#include <QGraphicsSceneDragDropEvent>
#include <QMimeData>

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
    if (e->mimeData()->hasColor()) {
        e->setAccepted(true);
        dragOver = true;
        update();
    } else {
        e->setAccepted(false);
    }
}

void RectItem::dragLeaveEvent(QGraphicsSceneDragDropEvent *e)
{
    Q_UNUSED(e);
    dragOver = false;
    update();
}

void RectItem::dropEvent(QGraphicsSceneDragDropEvent *e)
{
    dragOver = false;
    if (e->mimeData()->hasColor()) {
        color = qvariant_cast<QColor>(e->mimeData()->colorData());
        update();
    }
}


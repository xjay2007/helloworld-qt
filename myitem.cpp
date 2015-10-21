#include "myitem.h"
#include <QPainter>
#include <QCursor>
#include <QGraphicsSceneMouseEvent>
#include <QApplication>
#include <QDrag>
#include <QMimeData>
#include <QPixmap>
#include <QWidget>

MyItem::MyItem()
{
    setToolTip("Click and drag me");
    setCursor(QCursor(Qt::OpenHandCursor));
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFlag(QGraphicsItem::ItemIsMovable);
}

QRectF MyItem::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(0-penWidth/2, 0-penWidth/2, 20+penWidth, 20+penWidth);
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setBrush(color);
    painter->drawEllipse(0, 0, 20, 20);
}

void MyItem::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    if (e->button() != Qt::LeftButton) {
        e->ignore();
        return;
    }
    setCursor(QCursor(Qt::ClosedHandCursor));
}

void MyItem::mouseMoveEvent(QGraphicsSceneMouseEvent *e)
{
    bool isDrag = QLineF(e->screenPos(), e->buttonDownScreenPos(Qt::LeftButton)).length() >= QApplication::startDragDistance();
    if (!isDrag) {
        return;
    }

    auto drag = new QDrag(e->widget());
    auto mime = new QMimeData;
    drag->setMimeData(mime);
    mime->setColorData(color);

    QPixmap pix(21, 21);
    pix.fill(Qt::transparent);
    QPainter painter(&pix);
    paint(&painter, nullptr, nullptr);
    drag->setPixmap(pix);

    drag->setHotSpot(QPoint(10, 15));
    drag->exec();
    setCursor(QCursor(Qt::OpenHandCursor));
}

void MyItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *)
{
    setCursor(QCursor(Qt::OpenHandCursor));
}

void MyItem::keyPressEvent(QKeyEvent *e)
{
    moveBy(0, 10);
}


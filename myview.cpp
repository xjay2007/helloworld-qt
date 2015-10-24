#include "myview.h"
#include "myitem.h"
#include "rectitem.h"
#include <QGraphicsScene>

MyView::MyView()
{
    resize(400, 300);

    auto scene = new QGraphicsScene;
    setScene(scene);

    for (int i = 0; i < 5; ++i) {
        auto myItem = new MyItem;
        myItem->setPos(i*50+20, 100);
        scene->addItem(myItem);
    }
    auto rectItem = new RectItem;
    rectItem->setPos(100, 200);
    scene->addItem(rectItem);

    auto line = new QGraphicsLineItem(0, 50, 30, 50);
    scene->addItem(line);
}


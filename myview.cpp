#include "myview.h"
#include "myitem.h"
#include <QGraphicsScene>

MyView::MyView()
{
    auto scene = new QGraphicsScene;
    setScene(scene);

    auto myItem = new MyItem;
    scene->addItem(myItem);


}


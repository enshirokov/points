#include "view.h"

#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include <QMouseEvent>
#include <QApplication>
#include <QDrag>
#include <QMimeData>
#include <QDebug>

View::View(QWidget *parent)
    : QGraphicsView(parent),
      createPointFlag(false),
      deletePointFlag(false)
{
    scene = new QGraphicsScene;
    setScene(scene);

    //setDragMode(DragMode::ScrollHandDrag);

    //addPoint(QPoint(10, 10));
}
void View::resizeEvent(QResizeEvent *event)
{
    scene->setSceneRect(0, 0, viewport()->width(), viewport()->height());
}

void View::mousePressEvent(QMouseEvent *event)
{
    if(createPointFlag) {
        addPoint(event->pos());
    }

    if(deletePointFlag) {
        QGraphicsItem *item = itemAt(event->pos());
        scene->removeItem(item);
    }

    QGraphicsView::mousePressEvent(event);
}

void View::addPoint(const QPoint &p)
{

    QPointF mappedPoint = mapFromParent(p);
    Point *point = new Point(Qt::red, p.x(), p.y());
    //group->addToGroup(point);
    scene->addItem(point);


//    QTimeLine *timer = new QTimeLine(5000);
//    timer->setFrameRange(0, 100);

//    QGraphicsItemAnimation *animation = new QGraphicsItemAnimation;
//    animation->setItem(point);
//    animation->setTimeLine(timer);

//    for (int i = 0; i < 200; ++i)
//        animation->setPosAt(i / 200.0, QPointF(i, i));

//    timer->start();

}

void View::createPoint()
{
    createPointFlag = !createPointFlag;
    if(deletePointFlag)
        deletePointFlag = !deletePointFlag;

    qDebug() << "createPointFlag = " << createPointFlag;
}

void View::deletePoint()
{
    deletePointFlag = !deletePointFlag;

    if(createPointFlag)
        createPointFlag = false;

    qDebug() << "deletePointFlag = " << deletePointFlag;
}



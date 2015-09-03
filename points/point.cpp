#include "point.h"

#include <QGraphicsSceneDragDropEvent>
#include <QMimeData>
#include <QDrag>
#include <QPainter>
#include <QApplication>
#include <QBitmap>
#include <QObject>
#include <QWidget>
#include <QStyleOptionGraphicsItem>
#include <QDebug>


Point::Point(const QColor &color, int x, int y, QGraphicsItem *parent)
    : QGraphicsItem(parent)
{
    this->x0 = x;
    this->y0 = y;
    this->color = color;
    this->sX = x;
    this->sY = y;

    //this->setX(x);
    //this->setY(y);

    //qDebug() << "new point = " << QPoint(x0, y0);
    //setZValue((x + y) % 2);

    setFlags(ItemIsSelectable | ItemIsMovable);
    //setAcceptsHoverEvents(true);
}

QRectF Point::boundingRect() const
{
    //qDebug() << "boundingRect = " << QPoint(x0, y0);
    return QRectF(x0 - 5, y0 - 5, x0 + 5, y0 + 5);
}

QPainterPath Point::shape() const
{
    //qDebug() << "shape = " << QPoint(x0, y0);
    QPainterPath path;
    path.addEllipse(QPointF(x0, y0), 5, 5);
    return path;
}

void Point::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    qDebug() << "paint = " << mapToScene(this->pos());

//    x0 = this->x();
//    y0 = this->y();

    QColor fillColor = (option->state & QStyle::State_Selected) ? color.dark(150) : color;

//    QPen oldPen = painter->pen();
//    QPen pen = oldPen;
//    int width = 0;
//    if (option->state & QStyle::State_Selected)
//        width += 2;

//    pen.setWidth(width);
    QBrush b = painter->brush();
    painter->setBrush(QBrush(fillColor.dark(option->state & QStyle::State_Sunken ? 120 : 100)));
    painter->drawEllipse(QPointF(x0, y0), 5, 5);
    painter->setBrush(b);

    parentItem()->update();
}

void Point::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
    update();
}

void Point::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    //qDebug() << " mouseMoveEvent = " << event->scenePos();

    sX = event->scenePos().x();
    sY = event->scenePos().y();

    if (event->modifiers() & Qt::ShiftModifier) {
         update();
        return;
    }
    QGraphicsItem::mouseMoveEvent(event);
}

void Point::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);
    update();
}


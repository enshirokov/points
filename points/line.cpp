#include "line.h"
#include <QPainter>
#include <QStyle>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

Line::Line(const QColor &color, Point *p0, Point *p1, QGraphicsItem *parent)
    : QGraphicsLineItem(parent),
      color(color)
{
    this->p0 = p0;
    this->p1 = p1;

    setFlags(ItemIsSelectable | ItemIsMovable);
}

//QRectF Line::boundingRect() const
//{
//    return QGraphicsLineItem::boundingRect();
//}

//QPainterPath Line::shape() const
//{
//    return QGraphicsLineItem::shape();
//}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    qDebug() << "line update - " << p0->rx() << ", " << p0->ry();

    setLine(p0->rx(), p0->ry(), p1->rx(), p1->ry());

    QGraphicsLineItem::paint(painter, option, widget);
}

void Line::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
    update();
}

void Line::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    if (event->modifiers() & Qt::ShiftModifier) {
        update();
        return;
    }
    QGraphicsItem::mouseMoveEvent(event);
}

void Line::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);
    update();
}

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


Point::Point(const QColor &color, int x, int y)
{
    this->x = x;
    this->y = y;
    this->color = color;
    //setZValue((x + y) % 2);

    setFlags(ItemIsSelectable | ItemIsMovable);
    //setAcceptsHoverEvents(true);
}

QRectF Point::boundingRect() const
{
    return QRectF(x - 5, y - 5, y + 5, y + 5);
}

QPainterPath Point::shape() const
{
    QPainterPath path;
    path.addEllipse(QPointF(x, y), 5, 5);
    return path;
}

void Point::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    QColor fillColor = (option->state & QStyle::State_Selected) ? color.dark(150) : color;

//    QPen oldPen = painter->pen();
//    QPen pen = oldPen;
//    int width = 0;
//    if (option->state & QStyle::State_Selected)
//        width += 2;

//    pen.setWidth(width);
    QBrush b = painter->brush();
    painter->setBrush(QBrush(fillColor.dark(option->state & QStyle::State_Sunken ? 120 : 100)));
    painter->drawEllipse(QPointF(x, y), 5, 5);
    painter->setBrush(b);

}

void Point::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
    update();
}

void Point::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
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

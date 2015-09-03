#ifndef LINE_H
#define LINE_H

#include <QGraphicsItem>

#include "point.h"

class Line : public QGraphicsLineItem
{

public:
    explicit Line(const QColor &color, Point *p0, Point *p1, QGraphicsItem *parent = 0);

//    QRectF boundingRect() const;
//    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    Point *p0;
    Point *p1;
    QColor color;
};

#endif // LINE_H

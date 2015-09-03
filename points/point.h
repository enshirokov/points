#ifndef POINT_H
#define POINT_H

#include <QGraphicsItem>

class Point : public QGraphicsItem
{
public:
    explicit Point(const QColor &color = Qt::red, int x = 0, int y = 0, QGraphicsItem *parent = 0);
    //Point(const Point &other);

    //Point& operator= (const Point& other);

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget);

    qreal rx() { return sX; }
    qreal ry() { return sY; }


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    qreal x0, y0;
    qreal sX, sY;
    QColor color;
};

#endif // POINT_H

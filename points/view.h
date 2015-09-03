#ifndef MYVIEW_H
#define MYVIEW_H

#include <QGraphicsView>

#include "point.h"
#include "line.h"

class View : public QGraphicsView
{
    Q_OBJECT
public:
    explicit View(QWidget *parent = 0);

signals:

public slots:
    void addPoint(const QPoint &p);
    void createPoint();
    void deletePoint();
    void createLine();

protected:
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
//    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
//    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;

private:
    QGraphicsScene *scene;
    QGraphicsItemGroup *group;

    QGraphicsItem *currentDraggedItem;

    bool createPointFlag;
    bool deletePointFlag;
    bool createLineFlag;
};

#endif // MYVIEW_H

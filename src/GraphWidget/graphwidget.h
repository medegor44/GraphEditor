#ifndef GRAPHWIDGET
#define GRAPHWIDGET

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>

#include "../Graph/graph.h"

class GraphWidget : public QWidget
{
    Q_OBJECT

private:
    Graph graph;
    int currentPointIndex;
    bool waiting;

protected:
    void mousePressEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *e);

public:
    GraphWidget(QWidget *parent = 0);
};

#endif // GRAPHWIDGET


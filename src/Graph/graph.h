#ifndef GRAPH
#define GRAPH

#include <QVector>
#include <QPoint>

typedef QVector < QVector <int> > Matrix;

class Graph
{
private:
    Matrix  matrix;
    QVector <QPoint> points;

public:
    Graph()
    {}

    inline Matrix getMatrix() const
    { return matrix; }

    inline QVector <QPoint> getPoints() const
    { return points; }

    void addPoint(QPoint point); // Добавить точку на граф

    void removePointAt(int i);

    void connectDisconnectPoints(int i, int i1, int weight = 1);
    // Соединить 2 точки

    int getPointIndex(QPoint point); // Получить индекс точки в векторе
};

#endif // GRAPH


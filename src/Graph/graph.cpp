#include "graph.h"
#include <climits>

void Graph::addPoint(QPoint point)
{
    points.push_back(point);

    for(QVector <int> &v : matrix)
        v.push_back(0); // путь == 0 ? пути нет : путь есть

    matrix.push_back(QVector <int>(points.size()));
}

void Graph::removePointAt(int i)
{
    points.removeAt(i);

    for(QVector <int> &v : matrix)
        v.removeAt(i);

    matrix.removeAt(i);
}

int Graph::getPointIndex(QPoint point)
{
    for(int i = 0; i < points.size(); ++i)
        if((point - points[i]).manhattanLength() < 10)
            return i;

    return -1;
}

void Graph::connectDisconnectPoints(int i, int j, int weight)
{
    matrix[i][j] = matrix[j][i] = (matrix[i][j] ? 0 : weight);
}

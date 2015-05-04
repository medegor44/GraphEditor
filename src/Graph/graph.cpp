#include "graph.h"

void Graph::addPoint(QPoint point)
{
    points.push_back(point);

    for(QVector <int> &v : matrix) v.push_back(0);

    matrix.push_back(QVector <int>(points.size()));
}

void Graph::removePointAt(int i)
{
    points.removeAt(i);

    for(QVector <int> &v : matrix) v.removeAt(i);

    matrix.removeAt(i);
}

int Graph::getPointIndex(QPoint point)
{
    for(int i = 0; i < points.size(); ++i)
        if((point - points[i]).manhattanLength() < 15)
            return i;

    return -1;
}

void Graph::connectDisconnectPoints(int i, int i1, int weight)
{
    if(matrix[i][i1])
        matrix[i][i1] = matrix[i1][i] = 0;
    else
        matrix[i][i1] = matrix[i1][i] = weight;
}

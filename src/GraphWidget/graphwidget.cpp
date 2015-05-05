#include "graphwidget.h"

GraphWidget::GraphWidget(QWidget *parent)
    : QWidget(parent)
{
    waiting = false;
}

void GraphWidget::mousePressEvent(QMouseEvent *e)
{
    int pointIndex = graph.getPointIndex(e->pos());

    if(!waiting || pointIndex < 0) { // 2 точка не ожидается
        if(pointIndex < 0) // Если ее не существует на графе
            graph.addPoint(e->pos()); // Добавить
        else { // Существует
            currentPointIndex = pointIndex; // Запомнить
            waiting = true; // Ожидать 2 точку
        }
    } else { // 2 точка ожидается
        if(currentPointIndex == pointIndex) // Была выбрана та же самая точка
            graph.removePointAt(currentPointIndex); // Убрать с графа
        else
            graph.connectDisconnectPoints(currentPointIndex, pointIndex);
            // Соединить

        waiting = false; // Переключить на ожидание 1 точки
    }

    update();
}

void GraphWidget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(e->rect(), Qt::white);

    QPen fawPen(QBrush(Qt::red), 5, Qt::SolidLine, Qt::RoundCap);
    QPen usualPen(QBrush(Qt::blue), 5, Qt::SolidLine, Qt::RoundCap);

    QVector <QPoint> points = graph.getPoints();
    Matrix matrix = graph.getMatrix();

    usualPen.setWidth(2);
    painter.setPen(usualPen);
    for(int i = 0; i < matrix.size(); ++i)
        for(int j = i+1; j < matrix.size(); ++j)
            if(matrix[i][j])
                painter.drawLine(points[i], points[j]);

    usualPen.setWidth(5);
    for(QPoint p : points) {
        if(waiting && p == points[currentPointIndex])
            painter.setPen(fawPen); // Рисование выбранной точки
        else
            painter.setPen(usualPen); // Рисование обычной точки

        painter.drawPoint(p);
    }

}

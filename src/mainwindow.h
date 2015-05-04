#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "GraphWidget/graphwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    GraphWidget *graphWidget;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    graphWidget = new GraphWidget(this);
    setCentralWidget(graphWidget);
}

MainWindow::~MainWindow()
{

}

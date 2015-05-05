#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setGeometry(100, 100, 512, 512);

    mainFrame = new QFrame(this);
    mainLayout = new QHBoxLayout(mainFrame);

    graphWidget = new GraphWidget(this);
    mainLayout->addWidget(graphWidget);

    toolBox = new ToolBox(this);
    mainLayout->addWidget(toolBox);

    setCentralWidget(mainFrame);
}

MainWindow::~MainWindow()
{

}

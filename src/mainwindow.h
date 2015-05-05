#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFrame>
#include <QHBoxLayout>

#include "GraphWidget/graphwidget.h"
#include "ToolBox/toolbox.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    GraphWidget *graphWidget;
    ToolBox *toolBox;

    QHBoxLayout *mainLayout;
    QFrame *mainFrame;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H

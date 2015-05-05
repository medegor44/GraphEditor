#-------------------------------------------------
#
# Project created by QtCreator 2015-05-04T08:30:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GraphEditor
TEMPLATE = app
CONFIG += C++11


SOURCES += main.cpp\
        mainwindow.cpp \
    Graph/graph.cpp \
    GraphWidget/graphwidget.cpp \
    ToolBox/toolbox.cpp

HEADERS  += mainwindow.h \
    Graph/graph.h \
    GraphWidget/graphwidget.h \
    ToolBox/toolbox.h

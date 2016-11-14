QT += core
QT -= gui

TARGET = lab4
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++14

TEMPLATE = app

SOURCES += main.cpp \
    Point.cpp \
    circle.cpp \
    listnode.cpp \
    list.cpp

HEADERS += \
    Point.h \
    circle.h \
    listnode.h \
    list.h


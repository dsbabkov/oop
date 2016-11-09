QT += core
QT -= gui

TARGET = lab2
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++14

TEMPLATE = app

SOURCES += main.cpp \
    myString.cpp \
    shape.cpp \
    rect.cpp \
    circle.cpp \
    bin.cpp \
    hex.cpp \
    oct.cpp \
    mybyte.cpp

HEADERS += \
    myString.h \
    shape.h \
    rect.h \
    circle.h \
    bin.h \
    hex.h \
    oct.h \
    mybyte.h


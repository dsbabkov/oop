TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -O2

SOURCES += main.cpp \
    myString.cpp \
    Point.cpp \
    BD.cpp \
    Data.cpp \
    DataPair.cpp

HEADERS += \
    myString.h \
    Point.h \
    BD.h \
    Data.h \
    DataPair.h

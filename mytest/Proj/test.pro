QT += core
QT -= gui

CONFIG += c++11

TARGET = test
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    ../src/listener.cpp

INCLUDEPATH += /opt/ros/indigo/include \
               /usr/local/include

LIBS += /usr/local/lib/*.so \
     /opt/ros/indigo/lib/*.so

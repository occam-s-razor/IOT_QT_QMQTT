#-------------------------------------------------
#
# Project created by QtCreator 2019-06-16T21:56:39
#
#-------------------------------------------------

QT       += core gui network mqtt

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MQT
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gateway.cpp \
    videodevice.cpp \
    processImage.cpp \
    uarttest.cpp

HEADERS  += mainwindow.h \
    mqtt/include/qmqtt/qmqttDepends \
    gateway.h \
    videodevice.h \
    processImage.h \
    uarttest.h


FORMS    += mainwindow.ui

unix:!macx: LIBS += -L$$PWD/lib/ -lqmqtt

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib



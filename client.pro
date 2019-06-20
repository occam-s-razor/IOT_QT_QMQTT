TEMPLATE = app
TARGET = qmqtt_example
QT += core network qmqtt widgets

SOURCES += \
    example.cpp \
    gateway.cpp \
    videodevice.cpp \
    uarttest.cpp \
    processImage.cpp

target.path = $$[QT_INSTALL_EXAMPLES]/qmqtt/client
INSTALLS += target

HEADERS += \
    gateway.h \
    videodevice.h \
    uarttest.h \
    processImage.h

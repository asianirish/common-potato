TEMPLATE = lib
TARGET = potato-util

QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle
CONFIG += staticlib

DESTDIR = $$PWD/../build/lib/

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Action.cpp \
        Console.cpp \
        gfunc.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Action.h \
    Console.h \
    CuteFactory.h \
    Factory.h \
    gfunc.h

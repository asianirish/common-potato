TEMPLATE = lib
TARGET = uniq
DEFINES += UNIQLIB_LIBRARY

QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

LIBS +=  -L$$PWD/../build/lib/ -lpotato-util
INCLUDEPATH += $$PWD/../

DESTDIR = $$PWD/../build/lib/

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        CompactUuidValue.cpp \
        TimeQStringValue.cpp \
        TimeStringValue.cpp \
        TimeValue.cpp \
        UuidValue.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    CompactUuidValue.h \
    TimeQStringValue.h \
    TimeStringValue.h \
    TimeValue.h \
    UuidValue.h \
    Value.h \
    uniq_global.h

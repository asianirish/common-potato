TEMPLATE = lib
TARGET = hi

QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

LIBS +=  -L$$PWD/../build/lib/ -lpotato-util -luniq
INCLUDEPATH += $$PWD/../

DESTDIR = $$PWD/../build/lib/

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Exception.cpp \
        FieldDef.cpp \
        InvalidValueException.cpp \
        Item.cpp \
        Node.cpp \
        Serializer.cpp \
        SetFieldException.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Exception.h \
    FieldDef.h \
    InvalidValueException.h \
    Item.h \
    Node.h \
    Serializer.h \
    SetFieldException.h

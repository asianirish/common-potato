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
        FieldDef.cpp \
        Item.cpp \
        Node.cpp \
        Serializer.cpp \
        ex/Exception.cpp \
        ex/FieldException.cpp \
        ex/InvalidValueException.cpp \
        ex/JsonSerializer.cpp \
        ex/NoSuchField.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    FieldDef.h \
    Item.h \
    Node.h \
    Serializer.h \
    ex/Exception.h \
    ex/FieldException.h \
    ex/InvalidValueException.h \
    ex/JsonSerializer.h \
    ex/NoSuchField.h

TEMPLATE = lib
TARGET = hi

QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

LIBS +=  -L$$PWD/../build/lib/ -lpotato-util -luniq -lval
INCLUDEPATH += $$PWD/../

DESTDIR = $$PWD/../build/lib/

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ChildGroup.cpp \
        ItemRef.cpp \
        JsonSerializer.cpp \
        ex/Exception.cpp \
        FieldDef.cpp \
        ex/FieldException.cpp \
        ex/InvalidValueException.cpp \
        Item.cpp \
        ex/NoSuchField.cpp \
        Node.cpp \
        Serializer.cpp \
        ex/ValidatorException.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ChildGroup.h \
    ItemRef.h \
    JsonSerializer.h \
    ex/Exception.h \
    FieldDef.h \
    ex/FieldException.h \
    ex/InvalidValueException.h \
    Item.h \
    ex/NoSuchField.h \
    Node.h \
    Serializer.h \
    ex/ValidatorException.h

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
        JsonSerializer.cpp \
        ex/Exception.cpp \
        FieldDef.cpp \
        ex/FieldException.cpp \
        ex/InvalidValueException.cpp \
        Item.cpp \
        ex/NoSuchField.cpp \
        Node.cpp \
        Serializer.cpp \
        ex/ValidatorException.cpp \
        val/LessThan.cpp \
        val/LessThanOrEqualTo.cpp \
        val/List.cpp \
        val/MoreThan.cpp \
        val/MoreThanOrEqualTo.cpp \
        val/NotEqualTo.cpp \
        val/Range.cpp \
        val/Validator.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    JsonSerializer.h \
    ex/Exception.h \
    FieldDef.h \
    ex/FieldException.h \
    ex/InvalidValueException.h \
    Item.h \
    ex/NoSuchField.h \
    Node.h \
    Serializer.h \
    ex/ValidatorException.h \
    val/LessThan.h \
    val/LessThanOrEqualTo.h \
    val/List.h \
    val/MoreThan.h \
    val/MoreThanOrEqualTo.h \
    val/NotEqualTo.h \
    val/Range.h \
    val/Validator.h

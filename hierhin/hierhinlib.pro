TEMPLATE = lib
TARGET = hierhin

QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

LIBS +=  -L$$PWD/../build/lib/ -lpotato-util -luniq
INCLUDEPATH += $$PWD/../

DESTDIR = $$PWD/../build/lib/

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TRANSLATIONS += hierhin_ru.ts
TRANSLATIONS += hierhin_pl.ts
TRANSLATIONS += hierhin_en.ts


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Essence.h \
    Item.h \
    Node.h \
    def/ItemDef.h \
    def/ItemReq.h \
    def/NodeDef.h \
    def/PropertyDef.h \
    direct/ItemImpl.h \
    direct/NodeImpl.h \
    ex/CanNotBeEssenceless.h \
    ex/ChildItemException.h \
    ex/Exception.h \
    ex/IncompatibleEssenceClass.h \
    ex/InvalidValueException.h \
    ex/NoSuchProperty.h \
    ex/NoSuchRole.h \
    ex/PropertyException.h \
    ex/UnregisteredClassException.h \
    ex/ValidatorException.h

SOURCES += \
    Essence.cpp \
    Item.cpp \
    Node.cpp \
    def/ItemDef.cpp \
    def/ItemReq.cpp \
    def/NodeDef.cpp \
    def/PropertyDef.cpp \
    direct/ItemImpl.cpp \
    ex/CanNotBeEssenceless.cpp \
    ex/ChildItemException.cpp \
    ex/Exception.cpp \
    ex/IncompatibleEssenceClass.cpp \
    ex/InvalidValueException.cpp \
    ex/NoSuchProperty.cpp \
    ex/NoSuchRole.cpp \
    ex/PropertyException.cpp \
    ex/UnregisteredClassException.cpp \
    ex/ValidatorException.cpp



TEMPLATE = lib
CONFIG += staticlib
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
    Const.h \
    Essence.h \
    Item.h \
    ItemContainer.h \
    ItemContextSetter.h \
    ItemCreator.h \
    LinkEssence.h \
    LinkOwnerEssence.h \
    LinkableEssence.h \
    Method.h \
    Node.h \
    NodeMethod.h \
    cute/ItemCreatorImpl.h \
    cute/ItemImpl.h \
    cute/NodeImpl.h \
    def/ItemDef.h \
    def/ItemReq.h \
    def/MethodDef.h \
    def/NodeDef.h \
    def/PropertyDef.h \
    direct/ItemCreatorImpl.h \
    direct/ItemImpl.h \
    direct/NodeImpl.h \
    ex/CanNotBeEssenceless.h \
    ex/ChildItemException.h \
    ex/EmptyClassNameList.h \
    ex/EmptyPropertyName.h \
    ex/Exception.h \
    ex/IncompatibleArgNumber.h \
    ex/IncompatibleEssenceClass.h \
    ex/IncompatibleEssenceExecution.h \
    ex/IncompatibleValueType.h \
    ex/InvalidValueException.h \
    ex/NoItem.h \
    ex/NoSuchBaseType.h \
    ex/NoSuchLinkOwner.h \
    ex/NoSuchProperty.h \
    ex/NoSuchRole.h \
    ex/NotANode.h \
    ex/NotKindOf.h \
    ex/NotListType.h \
    ex/PropertyException.h \
    ex/UnregisteredClassException.h \
    ex/UnsupportedCommand.h \
    ex/ValidatorException.h \
    nav/ItemRef.h \
    nav/Path.h \
    nav/Step.h \
    sys/CallChildren.h \
    sys/GetChildByRole.h \
    sys/GetChildren.h \
    sys/GetClassName.h \
    sys/GetClassNames.h \
    sys/GetMethodNames.h \
    sys/GetName.h \
    sys/GetProperty.h \
    sys/SetLink.h \
    sys/SetProperty.h \
    type.h

SOURCES += \
    Const.cpp \
    Essence.cpp \
    Item.cpp \
    ItemContainer.cpp \
    ItemContextSetter.cpp \
    ItemCreator.cpp \
    LinkEssence.cpp \
    LinkOwnerEssence.cpp \
    LinkableEssence.cpp \
    Method.cpp \
    Node.cpp \
    NodeMethod.cpp \
    cute/ItemCreatorImpl.cpp \
    cute/ItemImpl.cpp \
    cute/NodeImpl.cpp \
    def/ItemDef.cpp \
    def/ItemReq.cpp \
    def/MethodDef.cpp \
    def/NodeDef.cpp \
    def/PropertyDef.cpp \
    ex/CanNotBeEssenceless.cpp \
    ex/ChildItemException.cpp \
    ex/EmptyClassNameList.cpp \
    ex/EmptyPropertyName.cpp \
    ex/Exception.cpp \
    ex/IncompatibleArgNumber.cpp \
    ex/IncompatibleEssenceClass.cpp \
    ex/IncompatibleEssenceExecution.cpp \
    ex/IncompatibleValueType.cpp \
    ex/InvalidValueException.cpp \
    ex/NoItem.cpp \
    ex/NoSuchBaseType.cpp \
    ex/NoSuchLinkOwner.cpp \
    ex/NoSuchProperty.cpp \
    ex/NoSuchRole.cpp \
    ex/NotANode.cpp \
    ex/NotKindOf.cpp \
    ex/NotListType.cpp \
    ex/PropertyException.cpp \
    ex/UnregisteredClassException.cpp \
    ex/UnsupportedCommand.cpp \
    ex/ValidatorException.cpp \
    nav/ItemRef.cpp \
    nav/Path.cpp \
    nav/Step.cpp \
    sys/CallChildren.cpp \
    sys/GetChildByRole.cpp \
    sys/GetChildren.cpp \
    sys/GetClassName.cpp \
    sys/GetClassNames.cpp \
    sys/GetMethodNames.cpp \
    sys/GetName.cpp \
    sys/GetProperty.cpp \
    sys/SetLink.cpp \
    sys/SetProperty.cpp



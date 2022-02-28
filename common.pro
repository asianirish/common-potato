TEMPLATE = lib
CONFIG += staticlib
TARGET = common-potato

CONFIG += object_parallel_to_source

message(Current QT version: $${QT_MAJOR_VERSION}.$$QT_MINOR_VERSION)

#equals(QT_MAJOR_VERSION, 5):lessThan(QT_MINOR_VERSION, 15) {
    message(Qt $$QT_VERSION USING LESS THAN 5.15)
    include(fx.prf)
#}


QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

message($$PWD/build/lib/)

DESTDIR = $$PWD/build/lib/

INCLUDEPATH += menu
INCLUDEPATH += hierhin

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TRANSLATIONS += common_ru.ts
TRANSLATIONS += common_pl.ts
TRANSLATIONS += common_en.ts


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#!versionAtLeast(QT_VERSION, 5.15.2):error("Use at least Qt version 5.15.2")

HEADERS += \
    hierhin/Const.h \
    hierhin/Essence.h \
    hierhin/HierhinClassRegistry.h \
    hierhin/HierhinContextSetter.h \
    hierhin/HierhinDestructor.h \
    hierhin/Item.h \
    hierhin/ItemContainer.h \
    hierhin/ItemContextSetter.h \
    hierhin/ItemCreator.h \
    hierhin/LinkEssence.h \
    hierhin/LinkOwnerEssence.h \
    hierhin/LinkableEssence.h \
    hierhin/Method.h \
    hierhin/Node.h \
    hierhin/NodeMethod.h \
    hierhin/cute/ItemCreatorImpl.h \
    hierhin/cute/ItemImpl.h \
    hierhin/cute/NodeImpl.h \
    hierhin/def/ItemDef.h \
    hierhin/def/ItemReq.h \
    hierhin/def/MethodDef.h \
    hierhin/def/NodeDef.h \
    hierhin/def/PropertyDef.h \
    hierhin/direct/ItemCreatorImpl.h \
    hierhin/direct/ItemImpl.h \
    hierhin/direct/NodeImpl.h \
    hierhin/ex/CanNotBeEssenceless.h \
    hierhin/ex/ChildItemException.h \
    hierhin/ex/EmptyClassNameList.h \
    hierhin/ex/EmptyPropertyName.h \
    hierhin/ex/Exception.h \
    hierhin/ex/IncompatibleArgNumber.h \
    hierhin/ex/IncompatibleEssenceClass.h \
    hierhin/ex/IncompatibleEssenceExecution.h \
    hierhin/ex/IncompatibleValueType.h \
    hierhin/ex/InvalidValueException.h \
    hierhin/ex/NoItem.h \
    hierhin/ex/NoSuchBaseType.h \
    hierhin/ex/NoSuchLinkOwner.h \
    hierhin/ex/NoSuchProperty.h \
    hierhin/ex/NoSuchRole.h \
    hierhin/ex/NotANode.h \
    hierhin/ex/NotKindOf.h \
    hierhin/ex/NotListType.h \
    hierhin/ex/PropertyException.h \
    hierhin/ex/UnregisteredClassException.h \
    hierhin/ex/UnsupportedCommand.h \
    hierhin/ex/ValidatorException.h \
    hierhin/nav/ItemRef.h \
    hierhin/nav/Path.h \
    hierhin/nav/Step.h \
    hierhin/sys/CallChildren.h \
    hierhin/sys/GetChildByRole.h \
    hierhin/sys/GetChildren.h \
    hierhin/sys/GetClassName.h \
    hierhin/sys/GetClassNames.h \
    hierhin/sys/GetMethodNames.h \
    hierhin/sys/GetName.h \
    hierhin/sys/GetProperty.h \
    hierhin/sys/SetLink.h \
    hierhin/sys/SetProperty.h \
    hierhin/type.h \
    menu/Action.h \
    menu/ActionListener.h \
    menu/ActionThread.h \
    menu/Command.h \
    menu/CommandInfo.h \
    menu/CommandTranslator.h \
    menu/Console.h \
    menu/ContextSetter.h \
    menu/Destructor.h \
    menu/Error.h \
    menu/JsonCommandTranslator.h \
    menu/Launcher.h \
    menu/LineCommandTranslator.h \
    menu/Menu.h \
    menu/Result.h \
    menu/SimpleAction.h \
    menu/SyncLauncher.h \
    menu/ThisAppClassRegistry.h \
    menu/ThreadLauncher.h \
    menu/def/ActionDef.h \
    menu/def/ArgDef.h \
    menu/def/Constraint.h \
    menu/def/NotEqualConstraint.h \
    menu/math/Div.h \
    menu/math/Inc.h \
    menu/test/BuildPhrase.h \
    menu/type.h \
    menu/util/SetLanguage.h \
    uniq/CompactUuidValue.h \
    uniq/TimeQStringValue.h \
    uniq/TimeStringValue.h \
    uniq/TimeValue.h \
    uniq/UuidValue.h \
    uniq/Value.h \
    util/BaseWrapper.h \
    util/BiMap.h \
    util/CuteContainer.h \
    util/CuteFactory.h \
    util/Destructor.h \
    util/Factory.h \
    util/LazyPointer.h \
    util/LazyRegistry.h \
    util/NamedArgList.h \
    util/ObjectRegistry.h \
    util/SingletonRegistry.h \
    util/gfunc.h \
    val/AbstractRegex.h \
    val/Each.h \
    val/Email.h \
    val/Length.h \
    val/LessThan.h \
    val/LessThanOrEqualTo.h \
    val/List.h \
    val/MoreThan.h \
    val/MoreThanOrEqualTo.h \
    val/NotEqualTo.h \
    val/Phone.h \
    val/Range.h \
    val/TypeValidator.h \
    val/Validator.h

SOURCES += \
    hierhin/Const.cpp \
    hierhin/Essence.cpp \
    hierhin/HierhinClassRegistry.cpp \
    hierhin/HierhinContextSetter.cpp \
    hierhin/HierhinDestructor.cpp \
    hierhin/Item.cpp \
    hierhin/ItemContainer.cpp \
    hierhin/ItemContextSetter.cpp \
    hierhin/ItemCreator.cpp \
    hierhin/LinkEssence.cpp \
    hierhin/LinkOwnerEssence.cpp \
    hierhin/LinkableEssence.cpp \
    hierhin/Method.cpp \
    hierhin/Node.cpp \
    hierhin/NodeMethod.cpp \
    hierhin/cute/ItemCreatorImpl.cpp \
    hierhin/cute/ItemImpl.cpp \
    hierhin/cute/NodeImpl.cpp \
    hierhin/def/ItemDef.cpp \
    hierhin/def/ItemReq.cpp \
    hierhin/def/MethodDef.cpp \
    hierhin/def/NodeDef.cpp \
    hierhin/def/PropertyDef.cpp \
    hierhin/ex/CanNotBeEssenceless.cpp \
    hierhin/ex/ChildItemException.cpp \
    hierhin/ex/EmptyClassNameList.cpp \
    hierhin/ex/EmptyPropertyName.cpp \
    hierhin/ex/Exception.cpp \
    hierhin/ex/IncompatibleArgNumber.cpp \
    hierhin/ex/IncompatibleEssenceClass.cpp \
    hierhin/ex/IncompatibleEssenceExecution.cpp \
    hierhin/ex/IncompatibleValueType.cpp \
    hierhin/ex/InvalidValueException.cpp \
    hierhin/ex/NoItem.cpp \
    hierhin/ex/NoSuchBaseType.cpp \
    hierhin/ex/NoSuchLinkOwner.cpp \
    hierhin/ex/NoSuchProperty.cpp \
    hierhin/ex/NoSuchRole.cpp \
    hierhin/ex/NotANode.cpp \
    hierhin/ex/NotKindOf.cpp \
    hierhin/ex/NotListType.cpp \
    hierhin/ex/PropertyException.cpp \
    hierhin/ex/UnregisteredClassException.cpp \
    hierhin/ex/UnsupportedCommand.cpp \
    hierhin/ex/ValidatorException.cpp \
    hierhin/nav/ItemRef.cpp \
    hierhin/nav/Path.cpp \
    hierhin/nav/Step.cpp \
    hierhin/sys/CallChildren.cpp \
    hierhin/sys/GetChildByRole.cpp \
    hierhin/sys/GetChildren.cpp \
    hierhin/sys/GetClassName.cpp \
    hierhin/sys/GetClassNames.cpp \
    hierhin/sys/GetMethodNames.cpp \
    hierhin/sys/GetName.cpp \
    hierhin/sys/GetProperty.cpp \
    hierhin/sys/SetLink.cpp \
    hierhin/sys/SetProperty.cpp \
    menu/Action.cpp \
    menu/ActionListener.cpp \
    menu/ActionThread.cpp \
    menu/Command.cpp \
    menu/CommandInfo.cpp \
    menu/CommandTranslator.cpp \
    menu/Console.cpp \
    menu/ContextSetter.cpp \
    menu/Destructor.cpp \
    menu/Error.cpp \
    menu/JsonCommandTranslator.cpp \
    menu/Launcher.cpp \
    menu/LineCommandTranslator.cpp \
    menu/Menu.cpp \
    menu/Result.cpp \
    menu/SimpleAction.cpp \
    menu/SyncLauncher.cpp \
    menu/ThisAppClassRegistry.cpp \
    menu/ThreadLauncher.cpp \
    menu/def/ActionDef.cpp \
    menu/def/ArgDef.cpp \
    menu/def/Constraint.cpp \
    menu/def/NotEqualConstraint.cpp \
    menu/math/Div.cpp \
    menu/math/Inc.cpp \
    menu/test/BuildPhrase.cpp \
    menu/util/SetLanguage.cpp \
    uniq/CompactUuidValue.cpp \
    uniq/TimeQStringValue.cpp \
    uniq/TimeStringValue.cpp \
    uniq/TimeValue.cpp \
    uniq/UuidValue.cpp \
    util/BaseWrapper.cpp \
    util/Destructor.cpp \
    util/gfunc.cpp \
    val/AbstractRegex.cpp \
    val/Each.cpp \
    val/Email.cpp \
    val/Length.cpp \
    val/List.cpp \
    val/NotEqualTo.cpp \
    val/Phone.cpp \
    val/TypeValidator.cpp \
    val/Validator.cpp

SUBDIRS += \
    uniq/uniq.pro

DISTFILES += \
    LICENSE.txt \
    TODO.txt \
    fx.prf

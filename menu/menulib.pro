TEMPLATE = lib
CONFIG += staticlib
TARGET = menu

QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

LIBS +=  -L$$PWD/../build/lib/ -lpotato-util -luniq
INCLUDEPATH += $$PWD/../

DESTDIR = $$PWD/../build/lib/

linux-g++ | linux-g++-64 | linux-g++-32 {
copydata.commands = $(COPY_DIR) $$PWD/*.qm $$OUT_PWD/../hierhin/
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata
}

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TRANSLATIONS += menulib_ru.ts
TRANSLATIONS += menulib_pl.ts
TRANSLATIONS += menulib_en.ts


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Action.h \
    CommandInfo.h \
    CommandTranslator.h \
    Console.h \
    Error.h \
    JsonCommandTranslator.h \
    Launcher.h \
    LineCommandTranslator.h \
    Menu.h \
    Result.h \
    SimpleAction.h \
    ThisAppClassRegistry.h \
    def/ActionDef.h \
    def/ArgDef.h \
    def/Constraint.h \
    def/NotEqualConstraint.h \
    math/Div.h \
    math/Inc.h \
    test/BuildPhrase.h \
    type.h \
    util/SetLanguage.h

SOURCES += \
    Action.cpp \
    CommandInfo.cpp \
    CommandTranslator.cpp \
    Console.cpp \
    Error.cpp \
    JsonCommandTranslator.cpp \
    Launcher.cpp \
    LineCommandTranslator.cpp \
    Menu.cpp \
    Result.cpp \
    SimpleAction.cpp \
    ThisAppClassRegistry.cpp \
    def/ActionDef.cpp \
    def/ArgDef.cpp \
    def/Constraint.cpp \
    def/NotEqualConstraint.cpp \
    math/Div.cpp \
    math/Inc.cpp \
    test/BuildPhrase.cpp \
    util/SetLanguage.cpp



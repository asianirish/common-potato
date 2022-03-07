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
    ActionListener.h \
    ActionThread.h \
    Command.h \
    CommandInfo.h \
    CommandTranslator.h \
    Console.h \
    ContextSetter.h \
    Destructor.h \
    Error.h \
    JsonCommandTranslator.h \
    Launcher.h \
    LineCommandTranslator.h \
    Menu.h \
    RedirectActionListener.h \
    Result.h \
    SimpleAction.h \
    SyncLauncher.h \
    TaskInfo.h \
    ThisAppClassRegistry.h \
    ThreadLauncher.h \
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
    ActionListener.cpp \
    ActionThread.cpp \
    Command.cpp \
    CommandInfo.cpp \
    CommandTranslator.cpp \
    Console.cpp \
    ContextSetter.cpp \
    Destructor.cpp \
    Error.cpp \
    JsonCommandTranslator.cpp \
    Launcher.cpp \
    LineCommandTranslator.cpp \
    Menu.cpp \
    RedirectActionListener.cpp \
    Result.cpp \
    SimpleAction.cpp \
    SyncLauncher.cpp \
    TaskInfo.cpp \
    ThisAppClassRegistry.cpp \
    ThreadLauncher.cpp \
    def/ActionDef.cpp \
    def/ArgDef.cpp \
    def/Constraint.cpp \
    def/NotEqualConstraint.cpp \
    math/Div.cpp \
    math/Inc.cpp \
    test/BuildPhrase.cpp \
    util/SetLanguage.cpp



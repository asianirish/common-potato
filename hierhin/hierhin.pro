QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

LIBS +=  -L$$PWD/../build/lib/ -lpotato-util -lmenu -luniq -lhierhin -lval
INCLUDEPATH += $$PWD/../


copydata.commands = $(COPY_DIR) $$PWD/*.qm $$OUT_PWD
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TRANSLATIONS += hierhin_ru.ts
TRANSLATIONS += hierhin_pl.ts
TRANSLATIONS += hierhin_en.ts

SOURCES += main.cpp \
    HierhinClassRegistry.cpp \
    Menu/CloneTest.cpp \
    Menu/CommandTest.cpp \
    Menu/LinkTest.cpp \
    Menu/NodeTest.cpp \
    Menu/NumberTest.cpp \
    Menu/TransTest.cpp \
    Menu/ValidatorTest.cpp \
    Test/TestEssenceA.cpp \
    Test/TestEssenceB.cpp \
    Test/TestEssenceC.cpp \
    stock_v0/Exchange.cpp


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    HierhinClassRegistry.h \
    Menu/CloneTest.h \
    Menu/CommandTest.h \
    Menu/LinkTest.h \
    Menu/NodeTest.h \
    Menu/NumberTest.h \
    Menu/TransTest.h \
    Menu/ValidatorTest.h \
    Test/TestEssenceA.h \
    Test/TestEssenceB.h \
    Test/TestEssenceC.h \
    stock_v0/Exchange.h



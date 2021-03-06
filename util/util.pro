QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

LIBS +=  -L$$PWD/../build/lib/ -lpotato-util -lmenu -luniq
INCLUDEPATH += $$PWD/../

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Test/TestA.cpp \
        Test/TestB.cpp \
        Test/TestC.cpp \
        Test/TestClassRegistry.cpp \
        Test/TestFactory.cpp \
        Test/TestLazy.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Test/TestA.h \
    Test/TestB.h \
    Test/TestC.h \
    Test/TestClassRegistry.h \
    Test/TestFactory.h \
    Test/TestLazy.h

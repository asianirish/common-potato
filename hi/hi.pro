QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

LIBS +=  -L$$PWD/../build/lib/ -lpotato-util -lmenu -luniq -lhi
INCLUDEPATH += $$PWD/../

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Exception.cpp \
        HiClassRegistry.cpp \
        SimpleObject.cpp \
        main.cpp \
        test/Currency.cpp \
        test/NewItem.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Exception.h \
    HiClassRegistry.h \
    SimpleObject.h \
    test/Currency.h \
    test/NewItem.h

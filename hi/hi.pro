QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

LIBS +=  -L$$PWD/../build/lib/ -lpotato-util -lmenu -luniq -lhi
INCLUDEPATH += $$PWD/../

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        HiClassRegistry.cpp \
        SimpleObject.cpp \
        main.cpp \
        test/ActionNewItem.cpp \
        test/ActionValidateUser.cpp \
        test/Bitcoin.cpp \
        test/Currency.cpp \
        test/User.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    HiClassRegistry.h \
    SimpleObject.h \
    test/ActionNewItem.h \
    test/ActionValidateUser.h \
    test/Bitcoin.h \
    test/Currency.h \
    test/User.h

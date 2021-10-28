TEMPLATE = lib
TARGET = val

QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

#LIBS +=  -L$$PWD/../build/lib/ -lpotato-util -luniq
INCLUDEPATH += $$PWD/../

DESTDIR = $$PWD/../build/lib/

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        AbstractRegex.cpp \
        Email.cpp \
        Length.cpp \
        List.cpp \
        NotEqualTo.cpp \
        Phone.cpp \
        Validator.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    AbstractRegex.h \
    Email.h \
    Length.h \
    LessThan.h \
    LessThanOrEqualTo.h \
    List.h \
    MoreThan.h \
    MoreThanOrEqualTo.h \
    NotEqualTo.h \
    Phone.h \
    Range.h \
    Validator.h
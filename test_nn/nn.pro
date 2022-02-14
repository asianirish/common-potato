QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

LIBS +=  -L$$PWD/../build/lib/ -lcommon-potato
INCLUDEPATH += $$PWD/../

DEFINES += USE_CUTE_IMPL

message($$PWD/../build/lib/)

SOURCES += \
        main.cpp \
        nn/Assoc.cpp \
        nn/Layer.cpp \
        nn/NNClassRegistry.cpp \
        nn/Neuron.cpp \
        nn/Perceptron.cpp \
        nn/PerceptronConstructor.cpp \
        nn/Task.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    nn/Assoc.h \
    nn/Layer.h \
    nn/NNClassRegistry.h \
    nn/Neuron.h \
    nn/Perceptron.h \
    nn/PerceptronConstructor.h \
    nn/Task.h

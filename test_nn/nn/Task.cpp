#include "Task.h"


#include <hierhin/type.h>
#include <hierhin/cute/NodeImpl.h>
#include <hierhin/ex/Exception.h>

#include <nn/Neuron.h>
#include <nn/Layer.h>
#include <nn/Perceptron.h>

#include <QDebug>

using namespace hierhin;
//using namespace hierhin::nav;

Task::Task(QObject *parent)
    : QObject{parent}
{

}

void Task::run()
{
    try {
        qDebug() << "TASK IS RUNNING";

        auto prc = NodePtr(new cute::NodeImpl());
        prc->setEssenceClassName(ESSENCE_CLASS(nn::Perceptron));

        auto layer0 = NodePtr(new cute::NodeImpl());
        layer0->setEssenceClassName(ESSENCE_CLASS(nn::Layer));

        prc->addChild(layer0, "layers");

        auto nd = NodePtr(new cute::NodeImpl());

        qDebug().noquote() << nd->toJson();

        nd->setEssenceClassName(ESSENCE_CLASS(nn::Neuron));
        nd->setProperty("value", 0.5);

        layer0->addChild(nd, "children");

        qDebug().noquote() << prc->toJson();

    }  catch (ex::Exception &e) {
        qDebug() << "ERROR:" << e.cause();
    }

    emit quit();
}

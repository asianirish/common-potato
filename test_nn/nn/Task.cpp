#include "Task.h"


#include <hierhin/type.h>
#include <hierhin/cute/NodeImpl.h>
#include <hierhin/ex/Exception.h>

#include <nn/Neuron.h>
#include <nn/Layer.h>
#include <nn/Perceptron.h>
#include <nn/Assoc.h>

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

        prc->addChild(layer0);

        auto nd0 = NodePtr(new cute::NodeImpl());
        auto nd1 = NodePtr(new cute::NodeImpl());

        nd0->setEssenceClassName(ESSENCE_CLASS(nn::Neuron));
        nd0->setProperty("value", 0.5);
        nd1->setEssenceClassName(ESSENCE_CLASS(nn::Neuron));
        nd1->setProperty("value", 0.1);

        nd0->setLink(nd1, true, Role(), ESSENCE_CLASS(nn::Assoc),
                     nn::Neuron::ASSOC_LINK_OWNER_ROLE)->setProperty("weight", 0.0333);;

        layer0->addChild(nd0);
        layer0->addChild(nd1);

        qDebug().noquote() << prc->toJson();

    }  catch (ex::Exception &e) {
        qDebug() << "ERROR:" << e.cause();
    }

    emit quit();
}
#include "Task.h"


#include <hierhin/type.h>
#include <hierhin/cute/NodeImpl.h>

#include <nn/Neuron.h>

#include <QDebug>

using namespace hierhin;
//using namespace hierhin::nav;

Task::Task(QObject *parent)
    : QObject{parent}
{

}

void Task::run()
{
    qDebug() << "TASK IS RUNNING";

    auto layer0 = NodePtr(new cute::NodeImpl());

    layer0->setEssenceClassName("nn::Layer");

    auto nd = NodePtr(new cute::NodeImpl());

    qDebug().noquote() << nd->toJson();

    nd->setEssenceClassName("nn::Neuron");
    nd->setProperty("value", 0.5);

    layer0->addChild(nd, "children");

    qDebug().noquote() << layer0->toJson();

    emit quit();
}

#include "Task.h"
#include "PerceptronConstructor.h"

#include <hierhin/type.h>
#include <hierhin/Node.h>
#include <hierhin/ex/Exception.h>

#include <QDebug>

//using namespace hierhin;
//using namespace hierhin::nav;

Task::Task(QObject *parent)
    : QObject{parent}
{

}

//double Task::dRand() const
//{
//    return potato_util::dRand(-1., 1.);
//}

void Task::run()
{
    qDebug() << "TASK IS RUNNING";

    try {
        nn::PerceptronConstructor constructor;
        constructor.setLayerSizes({3,2,1});
        auto prc = constructor.construct();
        qDebug() << "CONSTRUCTED";


//        auto prc = NodePtr(new cute::NodeImpl());
//        prc->setEssenceClassName(ESSENCE_CLASS(nn::Perceptron));

//        auto layer0 = NodePtr(new cute::NodeImpl());
//        layer0->setEssenceClassName(ESSENCE_CLASS(nn::Layer));

//        prc->addChild(layer0);

//        auto nd0 = NodePtr(new cute::NodeImpl());
//        auto nd1 = NodePtr(new cute::NodeImpl());

//        nd0->setEssenceClassName(ESSENCE_CLASS(nn::Neuron));
//        nd0->setProperty("value", dRand());
//        nd1->setEssenceClassName(ESSENCE_CLASS(nn::Neuron));
//        nd1->setProperty("value", dRand());

//        nd0->setLink(nd1, true, Role(), ESSENCE_CLASS(nn::Assoc),
//                     nn::Neuron::ASSOC_LINK_OWNER_ROLE)->setProperty("weight", dRand());;

//        layer0->addChild(nd0);
//        layer0->addChild(nd1);

        qDebug().noquote() << "PERCEPTRON:" << prc->toJson();

    }  catch (hierhin::ex::Exception &e) {
        qDebug() << "ERROR:" << e.cause();
    } catch (const QString strError) {
        qDebug() << "STR ERROR:" << strError;
    }

    emit quit();
}

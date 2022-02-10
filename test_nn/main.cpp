#include "nn/NNClassRegistry.h"

#include <QCoreApplication>

#include <iostream>
#include <QSharedPointer>

#include <hierhin/type.h>
#include <hierhin/cute/NodeImpl.h>

#include <nn/Neuron.h>


using namespace std;
using namespace nn;

using namespace hierhin;
using namespace hierhin::nav;
using namespace hierhin::cute;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout << "NN project" << endl;

    NNClassRegistry reg;
    reg.registerAllClasses();

//    auto neuron1 = hierhin::EssencePtr(new Neuron());
////    auto neuron2 = hierhin::EssencePtr(new Neuron());

    auto nd = NodePtr(new NodeHashImpl());

    qDebug().noquote() << nd->toJson();

    nd->setEssenceClassName("nn::Neuron");

    qDebug().noquote() << nd->toJson();


    return a.exec();
}

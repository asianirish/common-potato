#include "ChildTest.h"

#include <type.h>
#include <hierhin/direct/NodeImpl.h>

#include <QDebug>

using namespace hierhin;
using namespace hierhin::nav;
using namespace hierhin::direct;

ChildTest::ChildTest()
{

}

QVariant ChildTest::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args);

    qDebug() << "\n======================================================\n";
    auto nd = NodePtr(new NodeHashImpl());
    auto ndA = NodePtr(new NodeHashImpl());
    auto ndB = NodePtr(new NodeHashImpl());
    auto ndC = NodePtr(new NodeHashImpl());
    auto ndD = NodePtr(new NodeHashImpl());

    nd->setEssenceClassName("TestEssenceA");

    nd->addChild(ndA);
    nd->addChild(ndB);
    nd->addChild(ndC);
    nd->addChild(ndD);

    qDebug().noquote() << "NODE:" << nd->toJson();

    nd->execute("sys::GetChildren");
}

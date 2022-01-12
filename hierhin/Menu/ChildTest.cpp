#include "ChildTest.h"

#include <type.h>
#include <hierhin/direct/NodeImpl.h>

#include <QDebug>

using namespace hierhin;
using namespace hierhin::nav;
using namespace hierhin::direct;

ChildTest::ChildTest()
{
    _nd = NodePtr(new NodeHashImpl());
    auto ndA = NodePtr(new NodeHashImpl());
    auto ndB = NodePtr(new NodeHashImpl());
    auto ndC = NodePtr(new NodeHashImpl());
    auto ndD = NodePtr(new NodeHashImpl());

    _nd->setEssenceClassName("TestEssenceA");

    _nd->addChild(ndA);
    _nd->addChild(ndB);
    _nd->addChild(ndC);
    _nd->addChild(ndD);
}

QVariant ChildTest::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args);

    qDebug() << "\n======================================================\n";

    qDebug().noquote() << "NODE:" << _nd->toJson();

    _nd->execute("sys::GetChildren");

    return true;
}

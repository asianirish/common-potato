#include "LinkTest.h"

#include <hierhin/nav/ItemRef.h>
#include <hierhin/direct/NodeImpl.h>
#include <menu/Launcher.h>

#include <QDebug>

using namespace hierhin;
using namespace hierhin::nav;
using namespace hierhin::direct;

LinkTest::LinkTest()
{
    _nd = NodePtr(new NodeHashImpl());
    auto ndLeft = NodePtr(new NodeHashImpl());
    auto ndRight = NodePtr(new NodeHashImpl());
    auto link = NodePtr(new NodeHashImpl());

    _nd->setEssenceClassName("TestEssenceA");
    ndLeft->setEssenceClassName("TestEssenceB");
    ndRight->setEssenceClassName("TestEssenceA");

    ndLeft->setProperty("name", "Alice");
    ndRight->setProperty("name", "Bob");

    _nd->addChild(ndLeft, "left");
    _nd->addChild(ndRight, "right");

    ndLeft->setLink(ndRight->absPath());

}

QVariant LinkTest::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args)

    qDebug().noquote() << _nd->toJson();

    return true;
}

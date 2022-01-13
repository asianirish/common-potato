#include "HandMadeLinkTest.h"

#include <hierhin/nav/ItemRef.h>
#include <hierhin/direct/NodeImpl.h>
#include <menu/Launcher.h>

#include <QDebug>

using namespace hierhin;
using namespace hierhin::nav;
using namespace hierhin::direct;

HandMadeLinkTest::HandMadeLinkTest()
{
    _nd = NodePtr(new NodeHashImpl());
    auto ndA = NodePtr(new NodeHashImpl());
    auto ndB = NodePtr(new NodeHashImpl());
    auto linkOwner = NodePtr(new NodeHashImpl());
    auto link = NodePtr(new NodeHashImpl());

    _nd->setEssenceClassName("TestEssenceA");
    ndA->setEssenceClassName("hierhin::LinkedEssence");
    linkOwner->setEssenceClassName("hierhin::LinkOwnerEssence");
    link->setEssenceClassName("hierhin::LinkEssence");

    _nd->addChild(ndA);
    _nd->addChild(ndB);

    ndA->addChild(linkOwner, "links");
    linkOwner->addChild(link);

    ItemRef source(ndA->absPath());
    ItemRef target(ndB->absPath());

    link->setProperty("source", QVariant::fromValue(source));
    link->setProperty("target", QVariant::fromValue(target));

//TODO    ndA->execute("")

}

QVariant HandMadeLinkTest::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args)

    qDebug().noquote() << "NODE:" << _nd->toJson();

    return true;
}

void HandMadeLinkTest::onReady(const QVariant value, const menu::TaskId &taskId)
{
    //TODO: implement
    Q_UNUSED(value)
    Q_UNUSED(taskId)
    qDebug() << "ON_READY";
}

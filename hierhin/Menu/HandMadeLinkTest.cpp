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
    auto ndLeft = NodePtr(new NodeHashImpl());
    auto ndRight = NodePtr(new NodeHashImpl());
    auto linkOwner = NodePtr(new NodeHashImpl());
    auto link = NodePtr(new NodeHashImpl());

    connect(_nd->launcher().get(), &menu::Launcher::ready, this, &HandMadeLinkTest::onReady);

    _nd->setEssenceClassName("TestEssenceA");
    ndLeft->setEssenceClassName("TestEssenceB");
    ndRight->setEssenceClassName("TestEssenceA");

    ndLeft->setProperty("name", "Alla");
    ndRight->setProperty("name", "Boris");

    ndLeft->setEssenceClassName("hierhin::LinkedEssence");
    linkOwner->setEssenceClassName("hierhin::LinkOwnerEssence");
    link->setEssenceClassName("hierhin::LinkEssence");

    _nd->addChild(ndLeft, "left");
    _nd->addChild(ndRight, "right");

    ndLeft->addChild(linkOwner, "links");
    linkOwner->addChild(link);

    ItemRef source(ndLeft->absPath());
    ItemRef target(ndRight->absPath());

    link->setProperty("source", QVariant::fromValue(source));
    link->setProperty("target", QVariant::fromValue(target));
}

QVariant HandMadeLinkTest::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args)

    auto leftNode = _nd->childByRole("left");
    qDebug().noquote() << "NODE_A ID:" << leftNode->id();

    _getLinkOwnerId = leftNode->execute("sys::GetChildByRole", {"links"});
    qDebug() << "GET_LINK_OWNER_ID:" << _getLinkOwnerId;

    return true;
}

void HandMadeLinkTest::onReady(const QVariant value, const menu::TaskId &taskId)
{
    qDebug() << taskId << "VS." << _getLinkOwnerId;
    if (taskId == _getLinkOwnerId) {
        ItemRef ref(value.toString());

        qDebug() << "ON_READY" << value << taskId;
    }
}

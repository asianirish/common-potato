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
    auto link = NodePtr(new NodeHashImpl());

    connect(_nd->launcher().get(), &menu::Launcher::ready, this, &HandMadeLinkTest::onReady);

    _nd->setEssenceClassName("TestEssenceA");
    ndLeft->setEssenceClassName("TestEssenceB");
    ndRight->setEssenceClassName("TestEssenceA");

    ndLeft->setProperty("name", "Alla");
    ndRight->setProperty("name", "Boris");

    ndLeft->setEssenceClassName("hierhin::LinkableEssence");
    link->setEssenceClassName("hierhin::LinkEssence");

    auto linkOwner = ndLeft->childByRole(Const::DEFAULT_LINK_OWNER_ROLE);
    auto linkOwnerNd = linkOwner.dynamicCast<Node>();
    linkOwnerNd->addChild(link);

    _nd->addChild(ndLeft, "left");
    _nd->addChild(ndRight, "right");

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

    leftNode->execute("sys::GetChildByRole", {Const::DEFAULT_LINK_OWNER_ROLE}, &_getLinkOwnerId);

    return true;
}

void HandMadeLinkTest::onReady(const QVariant value, const menu::TaskId &taskId)
{
    qDebug() << taskId << "VS." << _getLinkOwnerId;
    if (taskId == _getLinkOwnerId) {
        ItemRef ref(value.value<nav::ItemRef>());
        auto linkOwnerNode = ref.ptr(_nd);
        qDebug().noquote() << "ON_READY GET LINK OWNER" << linkOwnerNode->toJson() << taskId;

        connect(linkOwnerNode->launcher().get(), &menu::Launcher::ready, this, &HandMadeLinkTest::onReady);
        linkOwnerNode->execute("sys::GetChildren", {}, &_getLinksId);
    } else if (taskId == _getLinksId){
        qDebug().noquote() << "ON_READY GET LINKS" << value << taskId;

        QList<nav::ItemRef> linkRefs = value.value<QList<nav::ItemRef>>();

        for (auto &linkRef : linkRefs) {
            auto link = linkRef.ptr(_nd);
            qDebug().noquote() << "LINK:" << link->toJson();

            auto source = link->refPtr("source");
            auto target = link->refPtr("target");

            qDebug().noquote() << "SOURCE:" << source->toJson();
            qDebug().noquote() << "TARGET:" << target->toJson();
        }

    } else {
        qDebug() << "SOMETHING FROM BEYOND" << value << taskId;
    }
}

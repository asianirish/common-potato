#include "HandMadeLinkTest.h"

#include <hierhin/nav/ItemRef.h>
#include <hierhin/direct/NodeImpl.h>

#include <hierhin/sys/GetChildByRole.h>
#include <hierhin/sys/GetChildren.h>

#include <hierhin/LinkableEssence.h>

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

    _nd->setEssenceClassName("TestEssenceA");
    ndLeft->setEssenceClassName("TestEssenceB");
    ndRight->setEssenceClassName("TestEssenceA");

    ndLeft->setProperty("name", "Alla");
    ndRight->setProperty("name", "Boris");

    ndLeft->setEssenceClassName(ESSENCE_CLASS(hierhin::LinkableEssence));
    link->setEssenceClassName(ESSENCE_CLASS(hierhin::LinkEssence));

    auto linkOwner = ndLeft->childByRole(LinkableEssence::DEFAULT_LINK_OWNER_ROLE);
    auto linkOwnerNd = linkOwner.dynamicCast<Node>();
    linkOwnerNd->addChild(link);

    _nd->addChild(ndLeft, "left");
    _nd->addChild(ndRight, "right");

    ItemRef source(ndLeft->absPath());
    ItemRef target(ndRight->absPath());

    link->setProperty(Const::SOURCE_PROP, QVariant::fromValue(source));
    link->setProperty(Const::TARGET_PROP, QVariant::fromValue(target));
}

QVariant HandMadeLinkTest::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args)

    auto leftNode = _nd->childByRole("left");
    qDebug().noquote() << "NODE_A ID:" << leftNode->id();

    leftNode->execute(METHOD_CLASS(sys::GetChildByRole), {LinkableEssence::DEFAULT_LINK_OWNER_ROLE});

    //TODO: call onReady here
    return true;
}

void HandMadeLinkTest::onReady(const QVariant value, const menu::TaskId &taskId)
{
    qDebug() << taskId << "VS." << _getLinkOwnerId;
    if (taskId == _getLinkOwnerId) {
        ItemRef ref(value.value<nav::ItemRef>());
        auto linkOwnerNode = ref.ptr(_nd);
        qDebug().noquote() << "ON_READY GET LINK OWNER" << linkOwnerNode->toJson() << taskId;

        linkOwnerNode->execute(METHOD_CLASS(sys::GetChildren));
    } else if (taskId == _getLinksId){
        qDebug().noquote() << "ON_READY GET LINKS" << value << taskId;

        QList<nav::ItemRef> linkRefs = value.value<QList<nav::ItemRef>>();

        for (auto &linkRef : linkRefs) {
            auto link = linkRef.ptr(_nd);
            qDebug().noquote() << "LINK:" << link->toJson();

            auto source = link->refPtr(Const::SOURCE_PROP);
            auto target = link->refPtr(Const::TARGET_PROP);

            qDebug().noquote() << "SOURCE:" << source->toJson();
            qDebug().noquote() << "TARGET:" << target->toJson();
        }

    } else {
        qDebug() << "SOMETHING FROM BEYOND" << value << taskId;
    }
}

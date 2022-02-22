#include "RefTest.h"
#include <hierhin/nav/Step.h>
#include <hierhin/nav/Path.h>
#include <hierhin/nav/ItemRef.h>

#include <type.h>
#include <hierhin/direct/NodeImpl.h>

#include <QDebug>

using namespace hierhin;
using namespace hierhin::nav;
using namespace hierhin::direct;

RefTest::RefTest()
{

}

QVariant RefTest::simplyAct(const QVariantList &args, const menu::TaskId &taskId)
{
    Q_UNUSED(args);
    Q_UNUSED(taskId)

    qDebug() << "\n======================================================\n";
    auto nd = NodePtr(new NodeHashImpl());
    auto ndA = NodePtr(new NodeHashImpl());
    auto ndB = NodePtr(new NodeHashImpl());
    auto ndC = NodePtr(new NodeHashImpl());
    auto ndD = NodePtr(new NodeHashImpl());

    ndC->setProperty("value", 1337);

    nd->addChild(ndA);
    ndA->addChild(ndB);
    ndB->addChild(ndC);

    Path pathC = ndC->absPath();
    ItemRef refToC(pathC);
    ndD->setProperty("ref", QVariant::fromValue<ItemRef>(refToC));
    nd->addChild(ndD);

    qDebug().noquote() << "NODE:" << nd->toJson();

    QVariant refVar = ndD->property("ref");
    auto ref = refVar.value<ItemRef>();

    qDebug().noquote() << "NODE_D.ref:" << ndD->refPtr("ref")->toJson();


    return true;
}

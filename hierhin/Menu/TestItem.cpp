#include "TestItem.h"
#include "Test/TestEssenceA.h"
#include "Test/TestEssenceB.h"

#include <util/SingletonRegistry.h>
#include <hierhin/direct/NodeImpl.h>

#include <QDebug>

using namespace hierhin;

TestItem::TestItem()
{

}

QVariant TestItem::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args);
    Item::setIdGenClassName("uniq::UuidValue");
    direct::ItemImpl item;

    QString value = "ID: " + item.id() + "\n";
    value += "ID second time: " + item.id() + "\n";

    auto nd1 = NodePtr(new direct::NodeHashImpl());
    auto nd2 = NodePtr(new direct::NodeHashImpl());

    nd1->setProperty("value", 13);
    nd2->setProperty("value", 37);

//    nd2->setParentNode(nd1.data());
    nd1->addChild(nd2);

    value += "NODE1 ID: " + nd1->id() + "\n";
    value += "NODE2 ID: " + nd2->id() + "\n";
    value += "NODE2'S PARENT ID: " + nd2->parentNode()->id() + "\n";

    auto nd3 = NodePtr(new direct::NodeHashImpl());
    nd3->setProperty("value", 1337);
    nd1->addChild(nd3);

    if (nd1->containsId(nd2->id())) {
        value += "NODE1 CONTAINS NODE2\n";
    }

    value += "NODE3 ID: " + nd3->id() + "\n";

    value += "\nNODE1 CHILDREN IDS:\n";

    auto ids = nd1->idList();

    for (auto &id : ids) {
        value += id + "\n";
    }

    auto testA = util::SingletonRegistry<hierhin::Essence>::ptr("TestEssenceA");
    testA->execute(nd1.data());

    auto testB = util::SingletonRegistry<hierhin::Essence>::ptr("TestEssenceB");
    testB->execute(nd2.data());

    value += "NODE1 AS A JSON: " + nd1->toJson();



    return value;
}

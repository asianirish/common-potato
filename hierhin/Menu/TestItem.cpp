#include "TestItem.h"

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

//    nd2->setParentNode(nd1.data());
    nd1->addChild(nd2);

    value += "NODE1 ID: " + nd1->id() + "\n";
    value += "NODE2 ID: " + nd2->id() + "\n";
    value += "NODE2'S PARENT ID: " + nd2->parentNode()->id() + "\n";

    if (nd1->containsId(nd2->id())) {
        value += "NODE1 CONTAINS NODE2";
    }



    return value;
}

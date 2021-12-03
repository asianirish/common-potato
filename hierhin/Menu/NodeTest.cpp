#include "NodeTest.h"
#include "NodeTest.h"
#include "Test/TestEssenceA.h"
#include "Test/TestEssenceB.h"

#include "ex/Exception.h"

#include <util/SingletonRegistry.h>
#include <hierhin/direct/NodeImpl.h>

#include <QDebug>
#include <iostream>

using namespace hierhin;

NodeTest::NodeTest()
{

}

QVariant NodeTest::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args);
    QString value;

//    Item::setIdGenClassName("uniq::UuidValue");
    try {
        direct::ItemImpl item;

        value = "ID: " + item.id() + "\n";
        value += "ID second time: " + item.id() + "\n";

        auto nd1 = NodePtr(new direct::NodeHashImpl());
        auto nd2 = NodePtr(new direct::NodeHashImpl());
        auto nd3 = NodePtr(new direct::NodeHashImpl());

        nd1->setEssenceClassName("TestEssenceA");
        nd2->setEssenceClassName("TestEssenceB");
        nd3->setEssenceClassName("TestEssenceA");

        int n;
        qDebug() << "enter nd1 value:";
        std::cin >> n;
        nd1->setProperty("value", n);

        qDebug() << "enter nd2 value:";
        std::cin >> n;
        nd2->setProperty("value", n);
        //TODO: uncomment this line to test a NoSuchProperty exception
//        nd1->setProperty("color", "red");

    //    nd2->setParentNode(nd1.data());
        nd1->addChild(nd2);

        value += "NODE1 ID: " + nd1->id() + "\n";
        value += "NODE2 ID: " + nd2->id() + "\n";
        value += "NODE2'S PARENT ID: " + nd2->parentNode()->id() + "\n";


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

        nd1->execute();
        nd2->execute();
        nd3->execute();

        value += "NODE1 AS A JSON: " + nd1->toJson();
    }  catch (ex::Exception &e) {
        qDebug() << "AN ERROR HAS OCCURRED:" << e.cause();
    }

    return value;
}

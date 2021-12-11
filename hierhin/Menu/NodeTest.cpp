#include "NodeTest.h"
#include "NodeTest.h"
#include "Test/TestEssenceA.h"
#include "Test/TestEssenceB.h"

#include "ex/Exception.h"

#include <util/SingletonRegistry.h>
#include <hierhin/direct/NodeImpl.h>
#include <menu/Console.h>

#include <QDebug>


using namespace hierhin;

NodeTest::NodeTest()
{

}

QVariant NodeTest::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args);

//    Item::setIdGenClassName("uniq::UuidValue");
    try {
        direct::ItemImpl item;

        qDebug() << "ID: " << item.id();
        qDebug() << "ID second time: " << item.id();

        auto nd1 = NodePtr(new direct::NodeHashImpl());
        auto nd2 = NodePtr(new direct::NodeHashImpl());
        auto nd3 = NodePtr(new direct::NodeHashImpl());

        nd1->setEssenceClassName("TestEssenceA");
        nd2->setEssenceClassName("TestEssenceB");
        nd3->setEssenceClassName("TestEssenceA");

        //test ex::UnregisteredClassExceptin
//        auto nd4 = NodePtr(new direct::NodeHashImpl());
//        nd4->setEssenceClassName("TestEssenceC");
//        nd1->addChild(nd4);

        int nnn;
        QTextStream qtin(stdin);
//        qDebug() << "enter nd1 value:";
        nnn = 13; //menu::Console::readInt();
        nd1->setProperty("value", nnn);

//        qDebug() << "enter nd1 email:";
        QString email = "someone@same.com"; //qtin.readLine();
        nd1->setProperty("email", email);

//        qDebug() << "enter nd1 phone:";
        QString phone = "+49000333444"; //qtin.readLine();
        nd1->setProperty("phone", phone);

//        qDebug() << "enter nd2 value:";
        nnn = 37; //menu::Console::readInt();
        nd2->setProperty("value", nnn);

        //TODO: uncomment this line to test a NoSuchProperty exception
//        nd1->setProperty("color", "red");

    //    nd2->setParentNode(nd1.data());
        nd1->addChild(nd2, "left");

        qDebug() << "NODE1 ID: " << nd1->id();
        qDebug() << "NODE2 ID: " << nd2->id();
        qDebug() << "NODE2'S PARENT ID: " << nd2->parentNode()->id();


        nd3->setProperty("value", 1337);
        nd1->addChild(nd3, "right");

        if (nd1->containsId(nd2->id())) {
            qDebug() << "NODE1 CONTAINS NODE2";
        }

        qDebug() << "NODE3 ID: " << nd3->id();

        qDebug() << "\nNODE1 CHILDREN IDS:\n";

        auto ids = nd1->idList();

        for (auto &id : ids) {
            qDebug() << "ID:" << id;
        }

        nd1->execute();
        nd2->execute();
        nd3->execute();

        qDebug().noquote() << "NODE1 AS A JSON: " << nd1->toJson();

        auto leftNode = nd1->childByRole("left");
        qDebug().noquote() << "LEFT NODE AS JSON: " << leftNode->toJson();

        auto rightNode = nd1->childByRole("right");
        qDebug().noquote() << "RIGHT NODE AS JSON: " << rightNode->toJson();

        qDebug() << "NODE1 CLASS NAMES:\n";
        auto clnms = nd1->essenceClassNames();
        for (auto &clnm : clnms) {
            qDebug() << clnm;
        }

        qDebug() << "NODE1 KIND OF QOBJECT: " << nd1->isKindOf("QObject");
        qDebug() << "NODE1 KIND OF hierhin::Essence: " << nd1->isKindOf("hierhin::Essence");
        qDebug() << "NODE1 KIND OF TestEssenceA: " << nd1->isKindOf("TestEssenceA");
        qDebug() << "NODE1 KIND OF TestEssenceB: " << nd1->isKindOf("TestEssenceB");

        //TODO: test with no essence
        auto ndWithouEssence = NodePtr(new direct::NodeHashImpl());
        auto ndWithouEssence1 = NodePtr(new direct::NodeHashImpl());
        ndWithouEssence->setProperty("spell", "abracadabra");
        ndWithouEssence1->setProperty("spell", "mutabor");
        ndWithouEssence->addChild(ndWithouEssence1);

        qDebug().noquote() << "NODE WITHOUT ESSENCE AS JSON: " << ndWithouEssence->toJson();

        qDebug() << "----------------test an essenceless child------------------";
        nd1->addChild(ndWithouEssence);
        qDebug().noquote() << "NODE1 AS A JSON: " << nd1->toJson();

    }  catch (ex::Exception &e) {
        qDebug() << "AN ERROR HAS OCCURRED:" << e.cause();
    }

    return true;
}

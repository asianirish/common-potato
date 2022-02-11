#include "MultyPropertyTest.h"
#include <hierhin/direct/NodeImpl.h>

#include <ex/Exception.h>

#include <QDebug>

using namespace hierhin;
using namespace hierhin::nav;
using namespace hierhin::direct;

MultyPropertyTest::MultyPropertyTest()
{

}

QVariant MultyPropertyTest::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args)

    try {
        NodePtr nd = NodePtr(new NodeHashImpl());
        nd->setEssenceClassName("TestEssenceMulty");

    //not necessarily:    nd->setProperty("numbers", QVariantList{});
        nd->addValue("numbers", 3);
        nd->addValue("numbers", 7);
        nd->addValue("numbers", 11);
    //try exception:    nd->addValue("numbers", 14);

        NodePtr nd0 = NodePtr(new NodeHashImpl());
        nd0->setEssenceClassName("TestEssenceMulty");
        NodePtr nd1 = NodePtr(new NodeHashImpl());
        nd1->setEssenceClassName("TestEssenceMulty");
        NodePtr nd2 = NodePtr(new NodeHashImpl());
        nd2->setEssenceClassName("TestEssenceMulty");
        NodePtr nd3 = NodePtr(new NodeHashImpl());
        nd3->setEssenceClassName("TestEssenceMulty");

        //set refs BEFORE seting children (works)
        nd0->addValue("refs", QVariant::fromValue(nav::ItemRef(nd1)));
        nd0->addValue("refs", QVariant::fromValue(nav::ItemRef(nd2)));
        nd0->addValue("refs", QVariant::fromValue(nav::ItemRef(nd3)));

        nd->addChild(nd0);
        nd->addChild(nd1);
        nd->addChild(nd2);
        nd->addChild(nd3);

//        nd0->addValue("refs", QVariant::fromValue(nav::ItemRef(nd1->absPath())));
//        nd0->addValue("refs", QVariant::fromValue(nav::ItemRef(nd2->absPath())));
//        nd0->addValue("refs", QVariant::fromValue(nav::ItemRef(nd3->absPath())));

        qDebug().noquote() << "NODE:" << nd->toJson();

    }  catch (ex::Exception &e) {
        qDebug() << "AN ERROR HAS OCCURRED:" << e.cause();
    } catch (const char *msg) {
        qDebug() << "A char * EXCEPTION HAS OCCURRED:" << msg;
    } catch (const QString &msg) {
        qDebug() << "A QString EXCEPTION HAS OCCURRED:" << msg;
    }



    return true;
}

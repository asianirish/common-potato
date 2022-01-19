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

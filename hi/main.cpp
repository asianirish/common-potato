#include "SimpleObject.h"

#include "Item.h"

#include "test/Currency.h"

#include <uniq/UuidValue.h>
#include <uniq/CompactUuidValue.h>
#include <uniq/TimeQStringValue.h>
#include <util/gfunc.h>


#include <QSharedPointer>
#include <QCoreApplication>
#include <QDebug>

void simpleTest() {
    SimpleObject *master = new SimpleObject();
    SimpleObject *slave = new SimpleObject(master);
    QSharedPointer<SimpleObject> sharedSlave = QSharedPointer<SimpleObject>(slave);

    master->setSimpleName("Master");
    slave->setSimpleName("Slave");

//TRY IT:    delete master;

    qDebug() << "The name of the slave is:" << slave->simpleName();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Hi";

    REGISTER_CLASS_FOR_UTIL_FACTORY(uniq::Value<QString>, uniq::UuidValue)
    REGISTER_CLASS_FOR_UTIL_FACTORY(uniq::Value<QString>, uniq::CompactUuidValue)
    REGISTER_CLASS_FOR_UTIL_FACTORY(uniq::Value<QString>, uniq::TimeQStringValue)

    hi::Item *item = new test::Currency();
    item->setField("code", "ETH");
    item->setField("usdPrice", 3391.03);

    qDebug() << "ITEM CLASS NAME:" << item->className();
    qDebug() << "ITEM TO MAP:" << item->toMap();

    hi::Item *itemClone = new test::Currency();

    itemClone->fromMap(item->toMap());
    qDebug() << "CLONE ITEM TO MAP:" << item->toMap();

    qDebug() << "-------------------------------------------------------";
    hi::Item *anotherItem = new test::Currency();
    anotherItem->setField("code", "TRASH");
    qDebug() << "ANOTHER ITEM CLASS NAME:" << anotherItem->className();
    qDebug() << "ANOTHER ITEM TO MAP:" << anotherItem->toMap();

    qDebug() << "ANOTHER ITEM USD_PRICE:" << anotherItem->field("usdPrice");
    qDebug() << "ANOTHER ITEM EU_PRICE:" << anotherItem->field("euPrice");


//TRY IT: simpleTest();

    return a.exec();
}

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

    qDebug() << "ITEM CLASS NAME:" << item->className();
    qDebug() << "ITEM TO MAP:" << item->toMap();




//TRY IT: simpleTest();

    return a.exec();
}

#include "SimpleObject.h"

#include "Item.h"

#include "test/Currency.h"
#include "HiClassRegistry.h"

#include "test/ActionNewItem.h"
#include "test/ActionValidateUser.h"

#include <uniq/UuidValue.h>
#include <uniq/CompactUuidValue.h>
#include <uniq/TimeQStringValue.h>
#include <util/gfunc.h>
#include <menu/Console.h>


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

    menu::Console console(new HiClassRegistry());

    //TODO: add items here
    console.addMenuItem("newitem", menu::ActionPtr(new test::ActionNewItem()));
    console.addMenuItem("validate", menu::ActionPtr(new test::ActionValidateUser()));

    console.run();
    QObject::connect(&console, SIGNAL(quit()), &a, SLOT(quit()));

//TRY IT: simpleTest();


    return a.exec();
}

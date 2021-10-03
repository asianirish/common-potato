#include "SimpleObject.h"

#include "Item.h"

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

    hi::Item *item = new hi::Item();
    qDebug() << "ITEM CLASS NAME: " << item->className();




//TRY IT: simpleTest();

    return a.exec();
}

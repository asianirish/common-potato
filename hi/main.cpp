#include "SimpleObject.h"

#include <QSharedPointer>
#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Hi";

    SimpleObject *master = new SimpleObject();
    SimpleObject *slave = new SimpleObject(master);
    QSharedPointer<SimpleObject> sharedSlave = QSharedPointer<SimpleObject>(slave);

    master->setSimpleName("Master");
    slave->setSimpleName("Slave");

//TRY IT:    delete master;

    qDebug() << "The name of the slave is:" << slave->simpleName();

    return a.exec();
}

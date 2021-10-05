#include "TestFactory.h"
#include "util/Factory.h"

#include <QDebug>

TestFactory::TestFactory()
{

}

void TestFactory::actSpecific(const QVariantList &args, const QString &taskId)
{
    Q_UNUSED(args);
    Q_UNUSED(taskId);

    {
        auto obj = util::Factory<QObject>::create("Hi::TestA");
        qDebug() << "Object:" << obj;
        qDebug() << "Class name:" << obj->metaObject()->className();
    }
    {
        auto obj = util::Factory<QObject>::create("Hi::TestB");
        qDebug() << "Object:" << obj;
        qDebug() << "Class name:" << obj->metaObject()->className();
    }
    {
        auto obj = util::Factory<QObject>::create("Hi::TestC");
        qDebug() << "Object:" << obj;
        qDebug() << "Class name:" << obj->metaObject()->className();
    }
}

menu::def::ActionDef TestFactory::actionDef() const
{
    return menu::def::ActionDef();
}

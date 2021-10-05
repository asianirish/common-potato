#include "TestFactory.h"
#include "util/Factory.h"

#include <QDebug>

TestFactory::TestFactory()
{

}

QVariant TestFactory::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args);
    QString ret("GENERATING TEST OBJECTS:\n\n");

    {
        auto obj = util::Factory<QObject>::create("Hi::TestA");
        ret += QString("Class name:") + obj->metaObject()->className() + "\n";
    }
    {
        auto obj = util::Factory<QObject>::create("Hi::TestB");
        ret += QString("Class name:") + obj->metaObject()->className() + "\n";
    }
    {
        auto obj = util::Factory<QObject>::create("Hi::TestC");
        ret += QString("Class name:")+ obj->metaObject()->className() + "\n";
    }
    return ret;
}

menu::def::ActionDef TestFactory::actionDef() const
{
    return menu::def::ActionDef();
}

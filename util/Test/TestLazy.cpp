#include "TestLazy.h"
#include "LazyPointer.h"
#include <uniq/Value.h>

#include <QString>

TestLazy::TestLazy()
{

}

QVariant TestLazy::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args);

    QString ret;
    {
        util::LazyPointer<uniq::Value<QString>> lp("uniq::TimeQStringValue");
        ret += QString("LAZY UNIQUE VALUE:") + lp->value() + "\n";
    }
    {
        util::LazyPointer<uniq::Value<QString>> lp("uniq::UuidValue");
        ret += QString("LAZY UNIQUE VALUE:") + lp->value() + "\n";
    }
    {
        util::LazyPointer<uniq::Value<QString>> lp("uniq::CompactUuidValue");
        ret += QString("LAZY UNIQUE VALUE:") + lp->value() + "\n";
    }

    return ret;
}

menu::def::ActionDef TestLazy::actionDef() const
{
    return menu::def::ActionDef();
}

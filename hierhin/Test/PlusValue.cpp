#include "PlusValue.h"

PlusValue::PlusValue()
{

}

QVariant PlusValue::actImpl(const QVariantList &args, Item *item)
{
    double arg = args.at(0).toDouble();
    double val = item->property("value").toDouble();
    double ret = val + arg;
    item->setProperty("value", ret);
    return ret;
}

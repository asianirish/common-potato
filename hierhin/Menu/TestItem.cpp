#include "TestItem.h"

#include <hierhin/direct/ItemImpl.h>

#include <QDebug>

using namespace hierhin;

TestItem::TestItem()
{

}

QVariant TestItem::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args);
    Item::setIdGenClassName("uniq::UuidValue");
    direct::ItemMapImpl item;

    QString value = "ID: " + item.id();
    return value;
}

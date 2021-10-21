#include "TestItem.h"

#include <hierhin/Abstract/Item.h>

#include <QDebug>

using namespace hierhin;

TestItem::TestItem()
{

}

QVariant TestItem::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args);
    Item::setIdGenClassName("uniq::UuidValue");
    Item item;

    QString value = "ID: " + item.id();
    return value;
}

#include "TestEssenceA.h"

#include <hierhin/Item.h>

#include <QDebug>

TestEssenceA::TestEssenceA()
{

}

void TestEssenceA::execute(hierhin::Item *item)
{
    Q_UNUSED(item);
    int value = item->property("value").toInt();
    item->setProperty("value", value * 2);
}

#include "TestEssenceB.h"

#include <hierhin/Item.h>

#include <QDebug>

TestEssenceB::TestEssenceB()
{

}

void TestEssenceB::execute(hierhin::Item *item)
{
    item->setProperty("pi", 3.1415926535);
}

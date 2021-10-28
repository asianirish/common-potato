#include "TestEssenceB.h"

#include <QDebug>

TestEssenceB::TestEssenceB()
{

}

void TestEssenceB::execute(hierhin::Item *item)
{
    Q_UNUSED(item);
    qDebug() << "THIS IS TEST_ESSENCE_B";
}

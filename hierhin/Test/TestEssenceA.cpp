#include "TestEssenceA.h"

#include <QDebug>

TestEssenceA::TestEssenceA()
{

}

void TestEssenceA::execute(hierhin::Item *item)
{
    Q_UNUSED(item);
    qDebug() << "THIS IS TEST_ESSENCE_A";
}

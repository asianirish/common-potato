#include "LinkTest.h"
#include <hierhin/nav/Step.h>

#include <QDebug>

using namespace hierhin::nav;

LinkTest::LinkTest()
{

}

QVariant LinkTest::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args);

    Step step0 = QString("PARENT");
    Step step1("CHILD_ID:test1");

    qDebug() << "STEP_0:" << step0.toString();
    qDebug() << "STEP_1:" << step1.toString();

    return true;
}

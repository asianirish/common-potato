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

    Step step0 = "PARENT";
    Step step1("CHILD_ID:test1");
    Step step2;

    step2 = QString("CHILD_ROLE:test2");

    qDebug() << "STEP_0:" << step0.toString();
    qDebug() << "STEP_1:" << step1.toString();
    qDebug() << "STEP_2:" << step2.toString();


    return true;
}

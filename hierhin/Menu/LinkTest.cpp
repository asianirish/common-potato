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

    step2 = "CHILD_ROLE:test2";

    qDebug() << "STEP_0:" << step0;
    qDebug() << "STEP_1:" << step1;
    qDebug() << "STEP_2:" << step2;

    QStringList lst;
    lst << step0 << step1 << step2;

    for (auto &strStep : lst) {
        qDebug() << strStep;
    }

    return true;
}

#include "LinkTest.h"
#include <hierhin/nav/Step.h>
#include <hierhin/nav/Path.h>
#include <hierhin/nav/ItemRef.h>

#include <QDebug>

using namespace hierhin::nav;

LinkTest::LinkTest()
{

}

QVariant LinkTest::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args);

    Step step0 = "/";
    Step step1("CHILD_ID:test1");
    Step step2;

    step2 = "CHILD_ROLE:test2";

    qDebug() << "STEP_0:" << step0;
    qDebug() << "STEP_1:" << step1;
    qDebug() << "STEP_2:" << step2;

    QStringList lst;
    lst << step0 << step1 << step2;
    Path path(lst);

    QString pathStr = path.toString();
    qDebug() << "PATH:" << pathStr;

    Path copyPath(pathStr);

    qDebug() << "COPY PATH:" << copyPath;

    Path copy2Path("/CHILD_ID:aaa/CHILD_ROLE:bbb");
    qDebug() << "COPY2 PATH:" << copy2Path;

    {
        hierhin::nav::ItemRef nodeRef;
        QVariant var = QVariant::fromValue<hierhin::nav::ItemRef>(nodeRef);

        auto tp = var.userType();
        qDebug() << var << "NODE_REF TYPE:" << tp;

        qDebug() << "NODE_REF CAN CONVERT TO QSTRING:" << var.canConvert<QString>();
        QString pathStr("/CHILD_ID:aaa/CHILD_ROLE:bbb");
        var = pathStr;
        qDebug() << "QSTRING CAN CONVERT TO NODE_REF:" << var.canConvert<hierhin::nav::ItemRef>();

        hierhin::nav::ItemRef itemRef;
        itemRef = qvariant_cast<hierhin::nav::ItemRef>(var);
        qDebug() << "ITEM_REF:" << itemRef << var;

    }
    qDebug() << "\n";
    {
        TestType tt;
        QVariant var = QVariant::fromValue<TestType>(tt);

        auto tp = var.userType();
        qDebug() << var << "TEST_TYPE REF TYPE:" << tp;
    }
    qDebug() << "\n";
    {
        menu::Result result;
        QVariant var = QVariant::fromValue<menu::Result>(result);

        auto tp = var.userType();
        qDebug() << var << "MENU RESULT REF TYPE:" << tp;
    }
    qDebug() << "\n";
    {
        menu::Error error;
        QVariant var = QVariant::fromValue<menu::Error>(error);

        auto tp = var.userType();
        qDebug() << var << "MENU RESULT REF TYPE:" << tp;
    }
    return true;
}

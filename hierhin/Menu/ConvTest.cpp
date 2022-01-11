#include "ConvTest.h"
#include <hierhin/nav/ItemRef.h>

#include <QVariant>
#include <QDebug>

ConvTest::ConvTest()
{

}

QVariant ConvTest::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args)

    hierhin::nav::ItemRef itemRef;
    QVariant itemRefVar = QVariant::fromValue<hierhin::nav::ItemRef>(itemRef);

    auto itemRefType = itemRefVar.userType();
    qDebug() << itemRefVar << "ITEM_REF TYPE:" << itemRefType;

    TestType ttp;
    QVariant testVar = QVariant::fromValue<TestType>(ttp);

    auto testTypeType = testVar.userType();
    qDebug() << testVar << "TEST_TYPE TYPE:" << testTypeType;


    QVariant strVar("/.");
    bool yes = strVar.canConvert(itemRefType);
    if (yes) {
        qDebug() << "String can convert ot ItemRef";
    } else {
        qDebug() << "String can NOT convert ot ItemRef";
    }

    yes = strVar.canConvert(testTypeType);
    if (yes) {
        qDebug() << "String can convert ot TestType";
    } else {
        qDebug() << "String can NOT convert ot TestType";
    }

    return true;
}

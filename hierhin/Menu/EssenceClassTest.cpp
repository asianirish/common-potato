#include "EssenceClassTest.h"

#include "Test/TestEssenceA.h"

#include <hierhin/LinkableEssence.h>
#include <hierhin/LinkOwnerEssence.h>
#include <hierhin/LinkEssence.h>

#include <QDebug>

EssenceClassTest::EssenceClassTest()
{

}

QVariant EssenceClassTest::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args)
    qDebug() << ESSENCE_CLASS(hierhin::Essence);
    qDebug() << ESSENCE_CLASS(hierhin::LinkOwnerEssence);
    qDebug() << ESSENCE_CLASS(hierhin::LinkableEssence);
    qDebug() << ESSENCE_CLASS(hierhin::LinkEssence);
    qDebug() << ESSENCE_CLASS(TestEssenceA);
    return true;
}

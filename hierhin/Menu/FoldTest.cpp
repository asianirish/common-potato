#include "FoldTest.h"

#include <QDebug>

FoldTest::FoldTest()
{

}

QVariant FoldTest::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args)

    qDebug() << "FOLD TEST";

    return true;
}

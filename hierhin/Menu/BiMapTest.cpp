#include "BiMapTest.h"
#include <util/BiMap.h>

#include <QDebug>

using namespace potato_util;

BiMapTest::BiMapTest()
{

}

QVariant BiMapTest::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args)

    {
        BiMap<int, QString> mp;
        mp.insert(23, "Hey");
        mp.insert(32, "Hi");
        mp.insert(42, "Bye");

        for (auto s : mp) {
            qDebug() << "left:" << mp.reverseValue(s) << "right:" << s;
        }
    }

    return true;
}

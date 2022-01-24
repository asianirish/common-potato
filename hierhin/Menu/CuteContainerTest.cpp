#include "CuteContainerTest.h"
#include <util/CuteContainer.h>

using namespace potato_util;

CuteContainerTest::CuteContainerTest()
{

}

QVariant CuteContainerTest::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args)

    {
        CuteContainer<QString, int> cc;
        cc.append(12);
        cc.insert("zzz", 23);
        cc.insert("bbb", 32);
        cc.insert("aaa", 44);
        cc.append(55);

        for (auto num : cc) {
            qDebug() << "NUMBER:" << num;
        }

        for (auto &key : cc.keys()) {
            qDebug() << "KEY:" << key << "NUMBER:" << cc.value(key);
        }
    }

    return true;
}

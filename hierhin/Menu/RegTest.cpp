#include "RegTest.h"

#include <util/ObjectRegistry.h>
#include <menu/SyncLauncher.h>
#include <menu/ThreadLauncher.h>

#include <QDebug>

using namespace potato_util;

RegTest::RegTest()
{

}

QVariant RegTest::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args)

    ObjectRegistry<int, menu::Launcher>::createObject<menu::SyncLauncher>(0);
    ObjectRegistry<int, menu::Launcher>::createObject<menu::ThreadLauncher>(0);

    auto lnch0 = ObjectRegistry<int, menu::Launcher>::ptr(0);
    auto lnch1 = ObjectRegistry<int, menu::Launcher>::ptr(0);

    lnch0->launch("menu::math::Inc", {12}, nullptr);
    lnch1->launch("menu::math::Div", {12, 3}, nullptr);


    return true;
}

#include "LauncherTest.h"

#include <menu/SyncLauncher.h>
#include <menu/ThreadLauncher.h>

#include <QDebug>

using namespace menu;

LauncherTest::LauncherTest()
{

}

QVariant LauncherTest::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args)

    ThreadLauncher threadLauncher;
    connect(&threadLauncher, &ThreadLauncher::ready, this, &LauncherTest::onReady);
    threadLauncher.launch("menu::math::Inc", {120});
    threadLauncher.launch("menu::math::Div", {132, 4});

//    SyncLauncher syncLauncher;
//    connect(&syncLauncher, &SyncLauncher::ready, this, &LauncherTest::onReady);
//    syncLauncher.launch("menu::math::Inc", {12});
//    syncLauncher.launch("menu::math::Div", {13, 4});

    return true;
}

void LauncherTest::onReady(const QVariant &result)
{
    qDebug() << "RESULT:" << result.toString();
}

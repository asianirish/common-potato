#include "LauncherTest.h"

#include <menu/SyncLauncher.h>

#include <QDebug>


LauncherTest::LauncherTest() : _threadLauncher(nullptr)
{
    _threadLauncher = new ThreadLauncher();
}

LauncherTest::~LauncherTest()
{
    if (_threadLauncher) {
        _threadLauncher->deleteLater();
    }
}

QVariant LauncherTest::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args)
//    connect(_threadLauncher, &ThreadLauncher::ready, this, &LauncherTest::onReady);
    _threadLauncher->launch("menu::math::Inc", {120});
    _threadLauncher->launch("menu::math::Div", {132, 4});

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

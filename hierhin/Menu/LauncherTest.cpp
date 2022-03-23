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

    _threadLauncher->launch("menu::math::Inc", {120}, nullptr);
    _threadLauncher->launch("menu::math::Div", {132, 4}, nullptr);

    SyncLauncher syncLauncher;
    syncLauncher.launch("menu::math::Inc", {12}, nullptr);
    syncLauncher.launch("menu::math::Div", {13, 4}, nullptr);

    return true;
}


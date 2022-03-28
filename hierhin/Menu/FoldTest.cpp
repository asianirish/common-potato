#include "FoldTest.h"

#include <menu/SyncLauncher.h>
#include <menu/math/Sum.h>
#include <menu/hof/Fold.h>

#include <QDebug>
#include <QVariant>

FoldTest::FoldTest()
{

}

QVariant FoldTest::simplyAct(const QVariantList &args)
{
    Q_UNUSED(args)

    qDebug() << "FOLD TEST";

    menu::SyncLauncher launcher;
    launcher.launch(ACTION_CLASS(menu::hof::Fold), {ACTION_CLASS(menu::math::Sum), 1,2,3}, menu::ContextSetterPtr());

    return true;
}

#ifndef LAUNCHERTEST_H
#define LAUNCHERTEST_H

#include <menu/SimpleAction.h>
#include <menu/ThreadLauncher.h>

using namespace menu;

class LauncherTest : public menu::SimpleAction
{
public:
    LauncherTest();

    virtual ~LauncherTest();

protected:
    QVariant simplyAct(const QVariantList &args) override;

private:
    ThreadLauncher *_threadLauncher;

    menu::def::ActionDef actionDef() const override {
        return menu::def::ActionDef();
    }

private slots:
    void onReady(const QVariant &result);
};

#endif // LAUNCHERTEST_H

#ifndef LAUNCHERTEST_H
#define LAUNCHERTEST_H

#include <menu/SimpleAction.h>

class LauncherTest : public menu::SimpleAction
{
public:
    LauncherTest();

protected:
    QVariant simplyAct(const QVariantList &args) override;

private:

    menu::def::ActionDef actionDef() const override {
        return menu::def::ActionDef();
    }

private slots:
    void onReady(const QVariant &result);
};

#endif // LAUNCHERTEST_H

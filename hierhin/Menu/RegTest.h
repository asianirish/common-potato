#ifndef REGTEST_H
#define REGTEST_H

#include <menu/SimpleAction.h>

class RegTest : public menu::SimpleAction
{
public:
    RegTest();

protected:
    QVariant simplyAct(const QVariantList &args, const menu::TaskId &taskId) override;

private:

    menu::def::ActionDef actionDef() const override {
        return menu::def::ActionDef();
    }
};

#endif // REGTEST_H

#ifndef REFTEST_H
#define REFTEST_H

#include <menu/SimpleAction.h>

class RefTest : public menu::SimpleAction
{
public:
    RefTest();

protected:
    QVariant simplyAct(const QVariantList &args, const menu::TaskId &taskId) override;

private:

    menu::def::ActionDef actionDef() const override {
        return menu::def::ActionDef();
    }
};

#endif // REFTEST_H

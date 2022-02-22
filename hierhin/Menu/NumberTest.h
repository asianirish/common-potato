#ifndef NUMBERTEST_H
#define NUMBERTEST_H

#include <menu/SimpleAction.h>

class NumberTest : public menu::SimpleAction
{
public:
    NumberTest();

protected:
    QVariant simplyAct(const QVariantList &args, const menu::TaskId &taskId) override;

private:

    menu::def::ActionDef actionDef() const override {
        return menu::def::ActionDef();
    }
};

#endif // NUMBERTEST_H

#ifndef COMMANDTEST_H
#define COMMANDTEST_H

#include <menu/SimpleAction.h>

class CommandTest : public menu::SimpleAction
{
public:
    CommandTest();

protected:
    QVariant simplyAct(const QVariantList &args, const menu::TaskId &taskId) override;

private:

    menu::def::ActionDef actionDef() const override {
        return menu::def::ActionDef();
    }
};

#endif // COMMANDTEST_H

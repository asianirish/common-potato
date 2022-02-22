#ifndef CUTECONTAINERTEST_H
#define CUTECONTAINERTEST_H

#include <menu/SimpleAction.h>

class CuteContainerTest : public menu::SimpleAction
{
public:
    CuteContainerTest();

protected:
    QVariant simplyAct(const QVariantList &args, const menu::TaskId &taskId) override;

private:

    menu::def::ActionDef actionDef() const override {
        return menu::def::ActionDef();
    }
};

#endif // CUTECONTAINERTEST_H

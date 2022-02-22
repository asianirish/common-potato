#ifndef METHODTEST_H
#define METHODTEST_H

#include <menu/SimpleAction.h>

class MethodTest : public menu::SimpleAction
{
public:
    MethodTest();

protected:
    QVariant simplyAct(const QVariantList &args, const menu::TaskId &taskId) override;

private:

    menu::def::ActionDef actionDef() const override {
        return menu::def::ActionDef();
    }
};

#endif // METHODTEST_H

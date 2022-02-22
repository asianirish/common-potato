#ifndef ESSENCECLASSTEST_H
#define ESSENCECLASSTEST_H

#include <menu/SimpleAction.h>

class EssenceClassTest : public menu::SimpleAction
{
public:
    EssenceClassTest();

protected:
    QVariant simplyAct(const QVariantList &args, const menu::TaskId &taskId) override;

private:

    menu::def::ActionDef actionDef() const override {
        return menu::def::ActionDef();
    }
};

#endif // ESSENCECLASSTEST_H

#ifndef MULTYPROPERTYTEST_H
#define MULTYPROPERTYTEST_H

#include <menu/SimpleAction.h>

class MultyPropertyTest : public menu::SimpleAction
{
public:
    MultyPropertyTest();

protected:
    QVariant simplyAct(const QVariantList &args) override;

private:
    menu::def::ActionDef actionDef() const override {
        return menu::def::ActionDef();
    }
};

#endif // MULTYPROPERTYTEST_H

#ifndef VALIDATORTEST_H
#define VALIDATORTEST_H

#include <menu/SimpleAction.h>

class ValidatorTest : public menu::SimpleAction
{
public:
    ValidatorTest();

protected:
    QVariant simplyAct(const QVariantList &args) override;

private:

    menu::def::ActionDef actionDef() const override {
        return menu::def::ActionDef();
    }
};

#endif // VALIDATORTEST_H

#ifndef ACTIONVALIDATEUSER_H
#define ACTIONVALIDATEUSER_H

#include <menu/SimpleAction.h>

namespace test {

class ActionValidateUser : public menu::SimpleAction
{
public:
    ActionValidateUser();

protected:
    QVariant simplyAct(const QVariantList &args) override;

private:

    menu::def::ActionDef actionDef() const override {
        return menu::def::ActionDef();
    }
};

} // namespace test

#endif // ACTIONVALIDATEUSER_H

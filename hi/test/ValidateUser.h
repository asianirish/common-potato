#ifndef VALIDATEUSER_H
#define VALIDATEUSER_H

#include <menu/SimpleAction.h>

namespace test {

class ValidateUser : public menu::SimpleAction
{
public:
    ValidateUser();

protected:
    QVariant simplyAct(const QVariantList &args) override;

private:

    menu::def::ActionDef actionDef() const override {
        return menu::def::ActionDef();
    }
};

} // namespace test

#endif // VALIDATEUSER_H

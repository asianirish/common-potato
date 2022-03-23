#ifndef LAZYREGISTRYTEST_H
#define LAZYREGISTRYTEST_H

#include <menu/SimpleAction.h>

class LazyRegistryTest : public menu::SimpleAction
{
public:
    LazyRegistryTest();

protected:
    QVariant simplyAct(const QVariantList &args) override;

private:

    menu::def::ActionDef actionDef() const override {
        return menu::def::ActionDef();
    }
};

#endif // LAZYREGISTRYTEST_H

#ifndef TESTFACTORY_H
#define TESTFACTORY_H

#include <menu/SimpleAction.h>

class TestFactory : public menu::SimpleAction
{
public:
    TestFactory();

protected:
    QVariant simplyAct(const QVariantList &args) override;

private:

    menu::def::ActionDef actionDef() const override;
};

#endif // TESTFACTORY_H

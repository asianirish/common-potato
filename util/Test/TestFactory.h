#ifndef TESTFACTORY_H
#define TESTFACTORY_H

#include <menu/Action.h>

class TestFactory : public menu::Action
{
public:
    TestFactory();

    // Action interface
private:
    void actSpecific(const QVariantList &args, const QString &taskId) override;
    menu::def::ActionDef actionDef() const override;
};

#endif // TESTFACTORY_H

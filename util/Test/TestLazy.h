#ifndef TESTLAZY_H
#define TESTLAZY_H

#include <menu/SimpleAction.h>

class TestLazy : public menu::SimpleAction
{
public:
    TestLazy();

protected:
    QVariant simplyAct(const QVariantList &args) override;

private:
    menu::def::ActionDef actionDef() const override;
};

#endif // TESTLAZY_H

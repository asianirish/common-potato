#ifndef CLONETEST_H
#define CLONETEST_H

#include <menu/SimpleAction.h>

class CloneTest : public menu::SimpleAction
{
public:
    CloneTest();

protected:
    QVariant simplyAct(const QVariantList &args) override;

private:

    menu::def::ActionDef actionDef() const override {
        return menu::def::ActionDef();
    }
};

#endif // CLONETEST_H

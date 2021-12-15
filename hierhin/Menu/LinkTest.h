#ifndef LINKTEST_H
#define LINKTEST_H

#include <menu/SimpleAction.h>

class LinkTest : public menu::SimpleAction
{
public:
    LinkTest();

protected:
    QVariant simplyAct(const QVariantList &args) override;

private:

    menu::def::ActionDef actionDef() const override {
        return menu::def::ActionDef();
    }
};

#endif // LINKTEST_H

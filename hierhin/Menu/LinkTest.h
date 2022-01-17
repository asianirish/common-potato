#ifndef LINKTEST_H
#define LINKTEST_H

#include <menu/SimpleAction.h>
#include <hierhin/type.h>

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

    hierhin::NodePtr _nd;

};

#endif // LINKTEST_H

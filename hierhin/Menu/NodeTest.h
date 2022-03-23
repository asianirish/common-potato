#ifndef NODETEST_H
#define NODETEST_H

#include <menu/SimpleAction.h>

class NodeTest : public menu::SimpleAction
{
public:
    NodeTest();

protected:
    QVariant simplyAct(const QVariantList &args) override;

private:

    menu::def::ActionDef actionDef() const override {
        return menu::def::ActionDef();
    }
};

#endif // NODETEST_H

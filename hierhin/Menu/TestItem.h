#ifndef TESTITEM_H
#define TESTITEM_H

#include <menu/SimpleAction.h>

class TestItem : public menu::SimpleAction
{
public:
    TestItem();

protected:
    QVariant simplyAct(const QVariantList &args) override;

private:

    menu::def::ActionDef actionDef() const override {
        return menu::def::ActionDef();
    }
};

#endif // TESTITEM_H

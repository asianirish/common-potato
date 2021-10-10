#ifndef TEST_NEWITEM_H
#define TEST_NEWITEM_H

#include <menu/SimpleAction.h>

namespace test {

class ActionNewItem : public menu::SimpleAction
{
public:
    ActionNewItem();

protected:
    QVariant simplyAct(const QVariantList &args) override;

private:

    menu::def::ActionDef actionDef() const override {
        return menu::def::ActionDef();
    }
};

} // namespace test

#endif // TEST_NEWITEM_H

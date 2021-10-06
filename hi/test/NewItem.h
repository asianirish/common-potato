#ifndef TEST_NEWITEM_H
#define TEST_NEWITEM_H

#include <menu/SimpleAction.h>

namespace test {

class NewItem : public menu::SimpleAction
{
public:
    NewItem();

protected:
    QVariant simplyAct(const QVariantList &args) override;

private:

    menu::def::ActionDef actionDef() const override {
        return menu::def::ActionDef();
    }
};

} // namespace test

#endif // TEST_NEWITEM_H

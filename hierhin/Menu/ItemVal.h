#ifndef ITEMVAL_H
#define ITEMVAL_H

#include <menu/SimpleAction.h>

class ItemVal : public menu::SimpleAction
{
public:
    ItemVal();

protected:
    QVariant simplyAct(const QVariantList &args) override;

private:

    menu::def::ActionDef actionDef() const override {
        return menu::def::ActionDef();
    }
};

#endif // ITEMVAL_H

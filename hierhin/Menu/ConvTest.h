#ifndef CONVTEST_H
#define CONVTEST_H

#include <menu/SimpleAction.h>

class ConvTest : public menu::SimpleAction
{
public:
    ConvTest();

protected:
    QVariant simplyAct(const QVariantList &args) override;

private:
    menu::def::ActionDef actionDef() const override {
        return menu::def::ActionDef();
    }
};

#endif // CONVTEST_H

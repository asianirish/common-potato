#ifndef TRANSTEST_H
#define TRANSTEST_H

#include <menu/SimpleAction.h>

class TransTest : public menu::SimpleAction
{
public:
    TransTest();

protected:
    QVariant simplyAct(const QVariantList &args) override;

private:

    menu::def::ActionDef actionDef() const override {
        return menu::def::ActionDef();
    }

};

#endif // TRANSTEST_H

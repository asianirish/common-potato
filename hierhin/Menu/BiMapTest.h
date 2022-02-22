#ifndef BIMAPTEST_H
#define BIMAPTEST_H

#include <menu/SimpleAction.h>

class BiMapTest : public menu::SimpleAction
{
public:
    BiMapTest();

protected:
    QVariant simplyAct(const QVariantList &args, const menu::TaskId &taskId) override;

private:

    menu::def::ActionDef actionDef() const override {
        return menu::def::ActionDef();
    }
};

#endif // BIMAPTEST_H

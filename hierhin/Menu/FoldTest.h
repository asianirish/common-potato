#ifndef FOLDTEST_H
#define FOLDTEST_H

#include <menu/SimpleAction.h>

class FoldTest : public menu::SimpleAction
{
public:
    FoldTest();

protected:
    QVariant simplyAct(const QVariantList &args) override;

private:

    menu::def::ActionDef actionDef() const override {
        return menu::def::ActionDef();
    }
};

#endif // FOLDTEST_H

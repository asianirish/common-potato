#ifndef CHILDTEST_H
#define CHILDTEST_H

#include <menu/SimpleAction.h>
#include <hierhin/type.h>

class ChildTest : public menu::SimpleAction
{
public:
    ChildTest();

protected:
    QVariant simplyAct(const QVariantList &args) override;

private:

    menu::def::ActionDef actionDef() const override {
        return menu::def::ActionDef();
    }

    hierhin::NodePtr _nd;

private slots:
    void onReady(const QVariant value);
};

#endif // CHILDTEST_H

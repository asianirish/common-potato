#ifndef HANDMADELINKTEST_H
#define HANDMADELINKTEST_H

#include <menu/SimpleAction.h>
#include <hierhin/type.h>

class HandMadeLinkTest : public menu::SimpleAction
{
public:
    HandMadeLinkTest();

protected:
    QVariant simplyAct(const QVariantList &args) override;

private:
    menu::def::ActionDef actionDef() const override {
        return menu::def::ActionDef();
    }

    hierhin::NodePtr _nd;

    menu::TaskId _getLinkOwnerId;

private slots:
    void onReady(const QVariant value, const menu::TaskId &taskId);
};

#endif // HANDMADELINKTEST_H

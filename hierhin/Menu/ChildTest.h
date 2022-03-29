#ifndef CHILDTEST_H
#define CHILDTEST_H

#include <menu/SimpleAction.h>
#include <menu/Redirector.h>
#include <hierhin/type.h>

class ChildTest : public menu::/*Simple*/Action
{
public:
    ChildTest();

protected:
    menu::Result actSpecific(const QVariantList &args, const menu::TaskId &taskId) override;

private:

    menu::def::ActionDef actionDef() const override {
        return menu::def::ActionDef();
    }

    hierhin::NodePtr _nd;

};

#endif // CHILDTEST_H

#ifndef MENU_SIMPLEACTION_H
#define MENU_SIMPLEACTION_H

#include "Action.h"

namespace menu {

class SimpleAction : public Action
{
public:
    SimpleAction();

    Result act(const QVariantList &args) final;

protected:
    virtual QVariant simplyAct(const QVariantList &args) = 0;
};

} // namespace menu

#endif // MENU_SIMPLEACTION_H

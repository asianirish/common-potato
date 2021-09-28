#ifndef MENU_SIMPLEACTION_H
#define MENU_SIMPLEACTION_H

#include "Action.h"

namespace menu {

class SimpleAction : public Action
{
public:
    SimpleAction();

protected:
    virtual QVariant simplyAct(const QVariantList &args) = 0;

private:
    void actSpecific(const QVariantList &args, const QString &taskId) final;

};

} // namespace menu

#endif // MENU_SIMPLEACTION_H

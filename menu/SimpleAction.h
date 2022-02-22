#ifndef MENU_SIMPLEACTION_H
#define MENU_SIMPLEACTION_H

#include "Action.h"

namespace menu {

class SimpleAction : public Action
{
public:
    SimpleAction();

protected:
    virtual QVariant simplyAct(const QVariantList &args, const TaskId &taskId) = 0;

    virtual bool isSync() const;

private:
    void actSpecific(const QVariantList &args, const TaskId &taskId) final;

};

} // namespace menu

#endif // MENU_SIMPLEACTION_H

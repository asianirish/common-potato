#ifndef MENU_SIMPLEACTION_H
#define MENU_SIMPLEACTION_H

#include "Action.h"

namespace menu {

class SimpleAction : public Action
{
public:
    SimpleAction();

    static QVariant simpleAct(const QString &simpleAction, const QVariantList &args);

protected:
    virtual QVariant simplyAct(const QVariantList &args) = 0;

private:
    Result actSpecific(const QVariantList &args, const TaskId &taskId) final;

};

} // namespace menu

#endif // MENU_SIMPLEACTION_H

#ifndef MENU_SIMPLEACTION_H
#define MENU_SIMPLEACTION_H

#include "Action.h"

namespace menu {

class SimpleAction : public Action
{
public:
    SimpleAction();

    bool isSync() const;
    void setIsSync(bool newIsSync);

protected:
    virtual QVariant simplyAct(const QVariantList &args, const TaskId &taskId) = 0;

private:
    void actSpecific(const QVariantList &args, const TaskId &taskId) final;

    bool _isSync;

};

} // namespace menu

#endif // MENU_SIMPLEACTION_H

#ifndef MENU_HOF_FOLD_H
#define MENU_HOF_FOLD_H

#include "SimpleAction.h"

namespace menu {
namespace hof {

class Fold : public SimpleAction
{
public:
    Fold();

protected:
    QVariant simplyAct(const QVariantList &args, const TaskId &taskId) override;
    bool isSync() const override;

private:
    def::ActionDef actionDef() const override;

    QVariant _acc;
    TaskId _taskId;

};

} // namespace hof
} // namespace menu

#endif // MENU_HOF_FOLD_H

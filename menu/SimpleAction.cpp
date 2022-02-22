#include "SimpleAction.h"

namespace menu {

SimpleAction::SimpleAction()
{

}

bool SimpleAction::isSync() const
{
    return true;
}

void SimpleAction::actSpecific(const QVariantList &args, const TaskId &taskId)
{
    if (isSync()) {
        Result result(simplyAct(args, taskId));
        result.setTaskId(taskId);
        emit ready(result);
    } else {
        simplyAct(args, taskId);
    }
}


} // namespace menu

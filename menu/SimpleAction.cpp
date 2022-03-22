#include "SimpleAction.h"

namespace menu {

SimpleAction::SimpleAction()
{

}

bool SimpleAction::isSync() const
{
    return true;
}

Result SimpleAction::actSpecific(const QVariantList &args, const TaskId &taskId)
{

    Result result(simplyAct(args, taskId));
    result.setTaskId(taskId);

    if (!isSync()) {
        emit done(result);        
    }

    return result;
}


} // namespace menu

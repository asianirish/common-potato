#include "SimpleAction.h"

namespace menu {

SimpleAction::SimpleAction()
{

}

Result SimpleAction::actSpecific(const QVariantList &args, const TaskId &taskId)
{
    Result result(simplyAct(args, taskId));
    result.setTaskId(taskId);

    emit done(result);

    return result;
}


} // namespace menu

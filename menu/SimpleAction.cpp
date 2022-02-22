#include "SimpleAction.h"

namespace menu {

SimpleAction::SimpleAction()
{

}

void SimpleAction::actSpecific(const QVariantList &args, const TaskId &taskId)
{
    //TODO: if (_isSync)
    Result result(simplyAct(args, taskId));
    result.setTaskId(taskId);
    emit ready(result);
}

} // namespace menu

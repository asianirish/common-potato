#include "SimpleAction.h"

namespace menu {

SimpleAction::SimpleAction()
{

}

void SimpleAction::actSpecific(const QVariantList &args, const TaskId &taskId)
{
    Result result(simplyAct(args));
    result.setTaskId(taskId);
    emit ready(result);
}

} // namespace menu

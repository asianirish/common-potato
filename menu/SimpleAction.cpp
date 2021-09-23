#include "SimpleAction.h"

namespace menu {

SimpleAction::SimpleAction()
{

}

Result SimpleAction::act(const QVariantList &args, const QString &taskId)
{
    Result result(simplyAct(args));
    result.setTaskId(taskId);
    emit ready(result);
    return result;
}

} // namespace menu

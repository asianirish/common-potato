#include "SimpleAction.h"

namespace menu {

SimpleAction::SimpleAction() : _isSync(true)
{

}

void SimpleAction::actSpecific(const QVariantList &args, const TaskId &taskId)
{
    if (_isSync) {
        Result result(simplyAct(args, taskId));
        result.setTaskId(taskId);
        emit ready(result);
    } else {
        simplyAct(args, taskId);
    }
}

bool SimpleAction::isSync() const
{
    return _isSync;
}

void SimpleAction::setIsSync(bool newIsSync)
{
    _isSync = newIsSync;
}

} // namespace menu

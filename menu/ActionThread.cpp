#include "ActionThread.h"

namespace menu {

ActionThread::ActionThread()
{

}

void ActionThread::run()
{
    _action->act(_args, _taskId);
}

ActionPtr ActionThread::action() const
{
    return _action;
}

void ActionThread::setAction(const ActionPtr &action)
{
    if (_action) {
        return;
    }

    _action = action;
    _action->moveToThread(this);

    connect(_action.get(), &Action::ready, this, &ActionThread::ready);
}

QVariantList ActionThread::args() const
{
    return _args;
}

void ActionThread::setArgs(const QVariantList &args)
{
    _args = args;
}

QString ActionThread::taskId() const
{
    return _taskId;
}

void ActionThread::setTaskId(const QString &taskId)
{
    _taskId = taskId;
}

} // namespace menu


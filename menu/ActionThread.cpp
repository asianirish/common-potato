#include "ActionThread.h"

#include <QDebug>

namespace menu {

ActionThread::ActionThread() : _action(nullptr)
{

}

void ActionThread::run()
{
    _action->act(_args, _taskId);
}

Action *ActionThread::action() const
{
    return _action;
}

void ActionThread::setAction(Action *action)
{
    if (_action) {
        return;
    }

    _action = action;
    _action->moveToThread(this);

    connect(_action, &Action::allListenersComplete, this, &ActionThread::onTestReady);
}

QVariantList ActionThread::args() const
{
    return _args;
}

void ActionThread::setArgs(const QVariantList &args)
{
    _args = args;
}

TaskId ActionThread::taskId() const
{
    return _taskId;
}

void ActionThread::setTaskId(const TaskId &taskId)
{
    _taskId = taskId;
}

void ActionThread::onTestReady(const menu::Result &result)
{
    qDebug() << "ON_TEST_READY" << result.value().toString();
    emit ready(result);
}

} // namespace menu


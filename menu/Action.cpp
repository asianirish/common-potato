#include "Action.h"
#include "ActionListener.h"

namespace menu {

Action::Action(QObject *parent) : QObject(parent),
    _listenerNum(0)
{

}

void Action::act(const QVariantList &args, const TaskId &taskId, const Listeners &listeners)
{
    auto actionDef = this->actionDef();
    auto err = actionDef.validate(args);

    if (err) {
        Result result;
        result.setTaskId(taskId);
        result.setError(err);
        emit ready(result);
        return;
    }

    _listenerNum = listeners.size();

    if (_listenerNum) {
        for (auto listener : listeners) {
            connect(this, &Action::ready, listener, &ActionListener::handleResult);
            connect(listener, &ActionListener::handled, this, &Action::onListenerHandled);
        }
    }

    QVariantList localArgs;

    actionDef.addDefaultArgs(args, localArgs);

    actSpecific(localArgs, taskId);

    if (!_listenerNum) {
        emit allListenersHandled();
    }
}

void Action::act(const QVariantMap &namedArgs, const TaskId &taskId, const Listeners &listeners)
{
    QVariantList args;
    actionDef().toPositionalArguments(namedArgs, args);

    act(args, taskId, listeners);
}

void Action::toPositionalArguments(const QVariantMap &namedArgs, QVariantList &posArgs)
{
    actionDef().toPositionalArguments(namedArgs, posArgs);
}

void Action::onListenerHandled()
{
    _listenerNum--;

    if (_listenerNum == 0) {
        emit allListenersHandled();
    }
}



} // namespace menu

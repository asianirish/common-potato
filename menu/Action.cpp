#include "Action.h"
#include "ActionListener.h"

#include <QDebug>

namespace menu {

Action::Action(QObject *parent) : QObject(parent),
    _listenerNum(0)
{

}

Result Action::act(const QVariantList &args, const TaskId &taskId, const Listeners &listeners)
{
    auto actionDef = this->actionDef();
    auto err = actionDef.validate(args);

    if (err) {
        Result result;
        result.setTaskId(taskId);
        result.setError(err);
        emit done(result);
        return result;
    }

    _listenerNum = listeners.size();

    if (_listenerNum) {
        for (auto listener : listeners) {
            connect(this, &Action::done, listener, &ActionListener::handleResult);
            connect(listener, &ActionListener::handled, this, &Action::onListenerHandled);
        }
    } else {
        connect(this, &Action::done, this, &Action::emitCompleteDebug); //TODO: connect(this, &Action::done, this, &Action::complete);
    }

    QVariantList localArgs;

    actionDef.addDefaultArgs(args, localArgs);

    return actSpecific(localArgs, taskId);
}

Result Action::act(const QVariantMap &namedArgs, const TaskId &taskId, const Listeners &listeners)
{
    QVariantList args;
    actionDef().toPositionalArguments(namedArgs, args);

    return act(args, taskId, listeners);
}

void Action::toPositionalArguments(const QVariantMap &namedArgs, QVariantList &posArgs)
{
    actionDef().toPositionalArguments(namedArgs, posArgs);
}

void Action::emitCompleteDebug(const menu::Result &result)
{
    emit allListenersComplete(result);
}

void Action::onListenerHandled(const Result &result)
{
    _listenerNum--;

    if (_listenerNum == 0) {
        emit allListenersComplete(result); //will be used the last result (same for all listeners)
    }
}



} // namespace menu

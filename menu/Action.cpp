#include "Action.h"
#include "ActionListener.h"

namespace menu {

Action::Action(QObject *parent) : QObject(parent)
{

}

void Action::act(const QVariantList &args, const TaskId &taskId, ActionListener *listener)
{
    auto actionDef = this->actionDef();
    auto err = actionDef.validate(args);

    if (listener) {
        connect(this, &Action::ready, listener, &ActionListener::onReady);
        //TODO: connect error
    }

    if (err) {
        Result result;
        result.setTaskId(taskId);
        result.setError(err);
        emit ready(result);
        return;
    }

    QVariantList localArgs;

    actionDef.addDefaultArgs(args, localArgs);

    actSpecific(localArgs, taskId);

}

void Action::act(const QVariantMap &namedArgs, const TaskId &taskId, ActionListener *listener)
{
    QVariantList args;
    actionDef().toPositionalArguments(namedArgs, args);

    act(args, taskId, listener);
}

void Action::toPositionalArguments(const QVariantMap &namedArgs, QVariantList &posArgs)
{
    actionDef().toPositionalArguments(namedArgs, posArgs);
}


} // namespace menu

#include "Action.h"

namespace menu {

Action::Action(QObject *parent) : QObject(parent)
{

}

void Action::act(const QVariantList &args, const QString &taskId)
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

    QVariantList localArgs;

    actionDef.addDefaultArgs(args, localArgs);

    actSpecific(localArgs, taskId);

}

void Action::act(const QVariantMap &namedArgs, const QString &taskId)
{
    QVariantList args;
    actionDef().toPositionalArguments(namedArgs, args);

    act(args, taskId);
}

void Action::toPositionalArguments(const QVariantMap &namedArgs, QVariantList &posArgs)
{
    actionDef().toPositionalArguments(namedArgs, posArgs);
}


} // namespace menu

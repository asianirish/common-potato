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

    //TODO: use defauilt values of the actionDef

    actSpecific(args, taskId);

}

} // namespace menu

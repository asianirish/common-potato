#include "Action.h"

namespace menu {

Action::Action(QObject *parent) : QObject(parent)
{

}

void Action::act(const QVariantList &args, const QString &taskId)
{
    for (auto &actionDef : _defs) {
        auto err = actionDef.validate(args);
        if (!err) {
            Result result;
            result.setTaskId(taskId);
            result.setError(err);
            emit ready(result);
        }
    }

    actSpecific(args, taskId);

}

void Action::addDef(const def::ActionDef &actionDef)
{
    _defs.append(actionDef);

}

} // namespace menu

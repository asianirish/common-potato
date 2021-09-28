#include "Action.h"

namespace menu {

Action::Action(QObject *parent) : QObject(parent)
{

}

void Action::act(const QVariantList &args, const QString &taskId)
{
    auto actionDefs = defs();

    for (auto &actionDef : actionDefs) {
        auto err = actionDef.validate(args);
        if (err) {
            Result result;
            result.setTaskId(taskId);
            result.setError(err);
            emit ready(result);
        }
    }

    actSpecific(args, taskId);

}

} // namespace menu

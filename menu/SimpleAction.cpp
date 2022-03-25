#include "SimpleAction.h"

#include <util/Factory.h>

namespace menu {

SimpleAction::SimpleAction()
{

}

QVariant SimpleAction::simpleAct(const QString &simpleAction, const QVariantList &args)
{
    Action *action = potato_util::Factory<Action>::create(simpleAction.toStdString());
    auto smpl = dynamic_cast<SimpleAction *>(action);

    if (!smpl) {
        if (action) {
            delete action;
        }

        //TODO: exception
        return QVariant();
    }

    auto val = smpl->simplyAct(args);

    delete action;

    return val;
}

Result SimpleAction::actSpecific(const QVariantList &args, const TaskId &taskId)
{
    Result result(simplyAct(args));
    result.setTaskId(taskId);

    emit done(result);

    return result;
}


} // namespace menu

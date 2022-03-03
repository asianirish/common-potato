#include "SyncLauncher.h"

#include "Action.h"

namespace menu {

SyncLauncher::SyncLauncher()
{

}

void SyncLauncher::launchImpl(Action *action, const QVariantList &args, const TaskId &taskId)
{
    connect(action, &Action::complete, this, &SyncLauncher::onActionComplete, Qt::DirectConnection); //emphasize that this is direct one
    action->act(args, taskId);
}

} // namespace menu

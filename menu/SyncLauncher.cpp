#include "SyncLauncher.h"

#include "Action.h"

namespace menu {

SyncLauncher::SyncLauncher(QObject *parent) : Launcher(parent)
{

}

void SyncLauncher::launchImpl(Action *action, const QVariantList &args, const TaskInfo &taskInfo)
{
    connect(action, &Action::allListenersComplete, this, &SyncLauncher::onActionComplete, Qt::DirectConnection); //emphasize that this is direct one
    action->act(args, taskInfo.taskId());
}

} // namespace menu

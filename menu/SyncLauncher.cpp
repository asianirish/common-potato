#include "SyncLauncher.h"

#include "Action.h"

namespace menu {

SyncLauncher::SyncLauncher()
{

}

void SyncLauncher::launchImpl(ActionPtr action, const QVariantList &args, const QString &actionId)
{
    connect(action.get(), &Action::ready, this, &SyncLauncher::onActionComplete, Qt::DirectConnection); //emphasize that this is direct one
    action->act(args, actionId);
}

} // namespace menu

#ifndef MENU_SYNCLAUNCHER_H
#define MENU_SYNCLAUNCHER_H

#include "Launcher.h"

namespace menu {

class SyncLauncher : public Launcher
{
public:
    SyncLauncher();

protected:
    void launchImpl(Action *action, const QVariantList &args, const TaskInfo &taskInfo = TaskInfo()) override;
};

} // namespace menu

#endif // MENU_SYNCLAUNCHER_H

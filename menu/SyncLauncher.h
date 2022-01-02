#ifndef MENU_SYNCLAUNCHER_H
#define MENU_SYNCLAUNCHER_H

#include "Launcher.h"

namespace menu {

class SyncLauncher : public Launcher
{
public:
    SyncLauncher();

protected:
    void launchImpl(ActionPtr action, const QVariantList &args, const QString &actionId) override;
};

} // namespace menu

#endif // MENU_SYNCLAUNCHER_H

#ifndef MENU_THREADLAUNCHER_H
#define MENU_THREADLAUNCHER_H

#include "Launcher.h"

namespace menu {

class ThreadLauncher : public Launcher
{
public:
    ThreadLauncher();

protected:
    void launchImpl(Action *action, const QVariantList &args, const QString &actionId) override;

};

} // namespace menu

#endif // MENU_THREADLAUNCHER_H

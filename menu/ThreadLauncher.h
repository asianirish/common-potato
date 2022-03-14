#ifndef MENU_THREADLAUNCHER_H
#define MENU_THREADLAUNCHER_H

#include "Launcher.h"

namespace menu {

class ThreadLauncher : public Launcher
{
public:
    explicit ThreadLauncher(QObject *parent = nullptr);

protected:
    void launchImpl(Action *action, const QVariantList &args, const TaskInfo &taskInfo = TaskInfo()) override;

};

} // namespace menu

#endif // MENU_THREADLAUNCHER_H

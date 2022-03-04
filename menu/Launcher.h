#ifndef MENU_LAUNCHER_H
#define MENU_LAUNCHER_H

#include "Result.h"
#include "type.h"
#include "ContextSetter.h"
#include "TaskInfo.h"

#include <util/LazyPointer.h>
#include <uniq/Value.h>

#include <QObject>

namespace menu {


//TODO: make ActionListener (?)
class Launcher : public QObject
{
    Q_OBJECT
public:
    explicit Launcher(QObject *parent = nullptr);

    void launch(const QString &actionClassName, const QVariantList &args, ContextSetterPtr cnxtSetter, const TaskInfo &taskInfo = TaskInfo());
    void launch(const QString &actionClassName, const QVariantMap &namedArgs, ContextSetterPtr cnxtSetter, const TaskInfo &taskInfo = TaskInfo());

protected:
    virtual void launchImpl(Action *action, const QVariantList &args, const TaskInfo &taskInfo = TaskInfo()) = 0;

    void onActionComplete(const menu::Result &result);

private:
    QMap<TaskId, Action *> _pendingActions;

    TaskId initAction(const QString &actionClassName, ContextSetterPtr cnxtSetter, const TaskInfo &taskInfo);

signals:
    void ready(const QVariant &result, const menu::TaskId &taskId);
    void error(const menu::Error &error);

};

} // namespace menu

#endif // MENU_LAUNCHER_H

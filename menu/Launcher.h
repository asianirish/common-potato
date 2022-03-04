#ifndef MENU_LAUNCHER_H
#define MENU_LAUNCHER_H

#include "Result.h"
#include "type.h"
#include "ContextSetter.h"

#include <util/LazyPointer.h>
#include <uniq/Value.h>

#include <QObject>

namespace menu {


//TODO: make ActionListener (?)
class Launcher : public QObject
{
    Q_OBJECT
public:
    [[deprecated]] static const QString DEFAULT_ACTION_ID_GENERATOR_CLASS_NAME;

    explicit Launcher(QObject *parent = nullptr);

    void launch(const QString &actionClassName, const QVariantList &args, ContextSetterPtr cnxtSetter, TaskId *taskIdOut = nullptr);
    void launch(const QString &actionClassName, const QVariantMap &namedArgs, ContextSetterPtr cnxtSetter, TaskId *taskIdOut = nullptr);

    static void setTaskIdGenClassName(const QString &className);

protected:
    virtual void launchImpl(Action *action, const QVariantList &args, const TaskId &taskId) = 0;

    void onActionComplete(const menu::Result &result);

private:
    QMap<TaskId, Action *> _pendingActions;

    //TODO: use QString as generated value but convert to TaskId
    static potato_util::LazyPointer<uniq::Value<QString>> _taskIdGen;

    TaskId initAction(const QString &actionClassName, ContextSetterPtr cnxtSetter);

signals:
    void ready(const QVariant &result, const menu::TaskId &taskId);
    void error(const menu::Error &error);

};

} // namespace menu

#endif // MENU_LAUNCHER_H

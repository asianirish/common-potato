#ifndef MENU_LAUNCHER_H
#define MENU_LAUNCHER_H

#include "Result.h"
#include "type.h"

#include <util/LazyPointer.h>
#include <uniq/Value.h>

#include <QObject>

namespace menu {

class ContextSetter;

//TODO: make ActionListener (?)
class Launcher : public QObject
{
    Q_OBJECT
public:
    static const QString DEFAULT_ACTION_ID_GENERATOR_CLASS_NAME;

    explicit Launcher(QObject *parent = nullptr);

    void launch(const QString &actionClassName, const QVariantList &args, ContextSetter *cnxtSetter, TaskId *taskIdOut = nullptr);
    void launch(const QString &actionClassName, const QVariantMap &namedArgs, ContextSetter *cnxtSetter, TaskId *taskIdOut = nullptr);

    static void setTaskIdGenClassName(const QString &className);

protected:
    virtual void launchImpl(Action *action, const QVariantList &args, const TaskId &taskId) = 0;

private:
    QMap<TaskId, Action *> _pendingActions;

    //TODO: use QString as generated value but convert to TaskId
    static potato_util::LazyPointer<uniq::Value<QString>> _taskIdGen;

    TaskId initAction(const QString &actionClassName, ContextSetter *cnxtSetter);

signals:
    void ready(const QVariant &result, const menu::TaskId &taskId);
    void error(const menu::Error &error);

protected:
    void onActionComplete(const menu::Result &result);

};

} // namespace menu

#endif // MENU_LAUNCHER_H

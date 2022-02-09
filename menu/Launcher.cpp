#include "Launcher.h"
#include "Action.h"
#include "ContextSetter.h"

#include <util/Factory.h>
#include <hierhin/type.h>

#include <QDebug>

QString stringListToString(const QStringList &lst) {
    int i = 0;
    QString retStr;

    for (auto &str : lst) {
        if (i) {
            retStr += ", ";
        }

        retStr += str;
        i++;
    }

    return retStr;
}

namespace menu {

const QString Launcher::DEFAULT_ACTION_ID_GENERATOR_CLASS_NAME("uniq::TimeQStringValue");

potato_util::LazyPointer<uniq::Value<QString>> Launcher::_taskIdGen(Launcher::DEFAULT_ACTION_ID_GENERATOR_CLASS_NAME);


Launcher::Launcher(QObject *parent) : QObject(parent)
{

}

TaskId Launcher::launch(const QString &actionClassName, const QVariantList &args, ContextSetterPtr cnxtSetter, TaskId *taskIdOut)
{
    TaskId taskId = initAction(actionClassName, cnxtSetter);

    if (taskIdOut) {
        *taskIdOut = taskId;
    }

    Action *action = _pendingActions.value(taskId);
    launchImpl(action, args, taskId);
    return taskId;
}

TaskId Launcher::launch(const QString &actionClassName, const QVariantMap &namedArgs, ContextSetterPtr cnxtSetter, TaskId *taskIdOut)
{
    TaskId taskId = initAction(actionClassName, cnxtSetter);

    if (taskIdOut) {
        *taskIdOut = taskId;
    }

    Action *action = _pendingActions.value(taskId);
    QVariantList args;
    action->toPositionalArguments(namedArgs, args);
    launchImpl(action, args, taskId);
    return taskId;
}

void Launcher::setTaskIdGenClassName(const QString &className)
{
    _taskIdGen.setClassName(className);
}

TaskId Launcher::initAction(const QString &actionClassName, ContextSetterPtr cnxtSetter)
{
    // will delete in Launcher::onActionComplete
    Action *action = potato_util::Factory<Action>::create(actionClassName.toStdString());

    if (cnxtSetter) {
        cnxtSetter->setActionContext(action);
    }

    QString taskId = _taskIdGen->value();
    //TODO: convert string taskId to TaskId class here
    _pendingActions.insert(taskId, action);

    return taskId;
}

void Launcher::onActionComplete(const Result &result)
{
    if (!_pendingActions.contains(result.taskId())) {
        Error err;
        err.setCode(Error::WRONG_TASK_ID);
        QVariantMap mp;
        mp.insert(tr("taskId"), result.taskId());
        err.setContext(mp);
        emit error(err);
        return;
    }

    auto action = _pendingActions.value(result.taskId());
    _pendingActions.remove(result.taskId());
    action->deleteLater();
//    delete action;

    if (result.errorCode() == Result::SUCCESSFUL_RESULT) {
        if (static_cast<QMetaType::Type>(result.value().type()) == QMetaType::QStringList) {
            QStringList lst = result.value().toStringList();
            qDebug() << "ACTION COMPLETE WITH RESULT:" << stringListToString(lst);
        } else if (result.value().userType() == QMetaType::type("hierhin::IdList")) {
            QStringList lst = result.value().value<hierhin::IdList>();
            qDebug() << "ACTION COMPLETE WITH RESULT (IdList):" << stringListToString(lst);
        } else {
            qDebug() << "ACTION COMPLETE WITH RESULT:" << result.value().toString();
        }
        emit ready(result.value(), result.taskId());
    } else {
        emit error(result.error());
    }
}

} // namespace menu

#include "Launcher.h"
#include "Action.h"
#include "ContextSetter.h"
#include "ActionListener.h"

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

Launcher::Launcher(QObject *parent) : QObject(parent)
{

}

void Launcher::launch(const QString &actionClassName, const QVariantList &args, ContextSetterPtr cnxtSetter, const TaskInfo &taskInfo)
{
    TaskId taskId = initAction(actionClassName, cnxtSetter, taskInfo);

    Action *action = _pendingActions.value(taskId);
    launchImpl(action, args, taskInfo);
}

void Launcher::launch(const QString &actionClassName, const QVariantMap &namedArgs, ContextSetterPtr cnxtSetter, const TaskInfo &taskInfo)
{
    TaskId taskId = initAction(actionClassName, cnxtSetter, taskInfo);

    Action *action = _pendingActions.value(taskId);
    QVariantList args;
    action->toPositionalArguments(namedArgs, args);
    launchImpl(action, args, taskInfo);
}

TaskId Launcher::initAction(const QString &actionClassName, ContextSetterPtr cnxtSetter, const TaskInfo &taskInfo)
{
    // will delete in Launcher::onActionComplete
    Action *action = potato_util::Factory<Action>::create(actionClassName.toStdString());

    if (cnxtSetter) {
        cnxtSetter->setActionContext(action);
    }

    auto listeners = taskInfo.listeners();
    for (auto lsr : listeners) {
        connect(action, &Action::allListenersComplete, lsr, &ActionListener::handleResult);
    }

    QString taskId = taskInfo.taskId();
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
        mp.insert(QString("taskId"), result.taskId());
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

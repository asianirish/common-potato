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

potato_util::LazyPointer<uniq::Value<QString>> Launcher::_actionIdGen(Launcher::DEFAULT_ACTION_ID_GENERATOR_CLASS_NAME);


Launcher::Launcher(QObject *parent) : QObject(parent)
{

}

void Launcher::launch(const QString &actionClassName, const QVariantList &args, ContextSetter *cnxtSetter)
{
    QString actionId = initAction(actionClassName, cnxtSetter);
    Action *action = _pendingActions.value(actionId);
    launchImpl(action, args, actionId);
}

void Launcher::launch(const QString &actionClassName, const QVariantMap &namedArgs, ContextSetter *cnxtSetter)
{
    QString actionId = initAction(actionClassName, cnxtSetter);
    Action *action = _pendingActions.value(actionId);
    QVariantList args;
    action->toPositionalArguments(namedArgs, args);
    launchImpl(action, args, actionId);
}

void Launcher::setActionIdGenClassName(const QString &className)
{
    _actionIdGen.setClassName(className);
}

QString Launcher::initAction(const QString &actionClassName, ContextSetter *cnxtSetter)
{
    // will delete in Launcher::onActionComplete
    Action *action = potato_util::Factory<Action>::create(actionClassName.toStdString());

    if (cnxtSetter) {
        cnxtSetter->setActionContext(action);
    }

    QString actionId = _actionIdGen->value();
    _pendingActions.insert(actionId, action);

    return actionId;
}

void Launcher::onActionComplete(const Result &result)
{
    if (!_pendingActions.contains(result.taskId())) {
        Error err;
        err.setCode(-1);
        err.setType(Error::ERROR_TYPE::LAUNCHER);
        err.setDescription(tr("no such an actionId"));
        QVariantMap mp;
        mp.insert(tr("actionId"), result.taskId());
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
        emit ready(result.value());
    } else {
        emit error(result.error());
    }
}

} // namespace menu

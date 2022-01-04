#include "Launcher.h"
#include "Action.h"
#include "ContextSetter.h"

#include <util/Factory.h>

#include <QDebug>

namespace menu {

const QString Launcher::DEFAULT_ACTION_ID_GENERATOR_CLASS_NAME("uniq::TimeQStringValue");

potato_util::LazyPointer<uniq::Value<QString>> Launcher::_actionIdGen(Launcher::DEFAULT_ACTION_ID_GENERATOR_CLASS_NAME);


Launcher::Launcher(QObject *parent) : QObject(parent),
    _contextSetter(nullptr)
{

}

void Launcher::launch(const QString &actionClassName, const QVariantList &args)
{
    QString actionId = initAction(actionClassName);
    Action *action = _pendingActions.value(actionId);
    launchImpl(action, args, actionId);
}

void Launcher::launch(const QString &actionClassName, const QVariantMap &namedArgs)
{
    QString actionId = initAction(actionClassName);
    Action *action = _pendingActions.value(actionId);
    QVariantList args;
    action->toPositionalArguments(namedArgs, args);
    launchImpl(action, args, actionId);
}

ContextSetter *Launcher::contextSetter() const
{
    return _contextSetter;
}

void Launcher::setContextSetter(ContextSetter *contextSetter)
{
    _contextSetter = contextSetter;
}

void Launcher::setActionIdGenClassName(const QString &className)
{
    _actionIdGen.setClassName(className);
}

QString Launcher::initAction(const QString &actionClassName)
{
    Action *action = potato_util::Factory<Action>::create(actionClassName.toStdString());

    if (_contextSetter) {
        _contextSetter->setActionContext(action);
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

    if (result.errorCode() == Result::SUCCESSFUL_RESULT) {
        qDebug() << "ACTION COMPLETE WITH RESULT:" << result.value().toString();
        emit ready(result.value());
    } else {
        emit error(result.error());
    }
}

} // namespace menu

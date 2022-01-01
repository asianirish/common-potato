#include "Launcher.h"
#include "Action.h"
#include "ContextSetter.h"

#include <util/Factory.h>

namespace menu {

const QString Launcher::DEFAULT_ACTION_ID_GENERATOR_CLASS_NAME("uniq::TimeQStringValue");

util::LazyPointer<uniq::Value<QString>> Launcher::_actionIdGen(Launcher::DEFAULT_ACTION_ID_GENERATOR_CLASS_NAME);


Launcher::Launcher(QObject *parent) : QObject(parent),
    _contextSetter(nullptr)
{

}

void Launcher::launch(const QString &actionClassName, QVariantList &args)
{
    Action *action = util::Factory<Action>::create(actionClassName.toStdString());
    ActionPtr actionPtr(action);

    if (_contextSetter) {
        _contextSetter->setActionContext(actionPtr);
    }

    QString actionId = _actionIdGen->value();
    _pendingActions.insert(actionId, actionPtr);
    launchImpl(actionPtr, args);
}

ContextSetter *Launcher::contextSetter() const
{
    return _contextSetter;
}

void Launcher::setContextSetter(ContextSetter *contextSetter)
{
    _contextSetter = contextSetter;
}

void Launcher::setTaskIdGenClassName(const QString &className)
{
    _actionIdGen.setClassName(className);
}

} // namespace menu

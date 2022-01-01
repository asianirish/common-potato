#include "Launcher.h"
#include "Action.h"
#include "ContextSetter.h"

#include <util/Factory.h>

namespace menu {

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

//TODO:    _pendingActions.insert(actionId, actionPtr);
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

} // namespace menu

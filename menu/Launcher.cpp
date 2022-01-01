#include "Launcher.h"
#include "Action.h"

#include <util/Factory.h>

namespace menu {

Launcher::Launcher(QObject *parent) : QObject(parent),
    _contextSetter(nullptr)
{

}

void Launcher::launch(const QString &actionClassName, QVariantList &args)
{
    /*Action *action = */util::Factory<Action>::create(actionClassName.toStdString());
//TODO:    ActionPtr actionPtr(action);
//TODO:    if (_contextSetter) _contextSetter->setActionContext(actionPtr);
//TODO:    registerAction(actionPtr);
//TODO:    launchImpl(actionPtr, args);
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

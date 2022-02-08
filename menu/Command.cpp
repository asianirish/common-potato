#include "Command.h"

namespace menu {

Command::Command() : Command(QString(), {})
{

}

Command::Command(const QString &actionClass, ContextSetterPtr contextSetter) : _actionClass(actionClass),
    _contextSetter(contextSetter)
{

}

const QString &Command::actionClass() const
{
    return _actionClass;
}

void Command::setActionClass(const QString &newActionClass)
{
    _actionClass = newActionClass;
}

ContextSetterPtr Command::contextSetter() const
{
    return _contextSetter;
}

void Command::setContextSetter(ContextSetterPtr newContexSetter)
{
    _contextSetter = newContexSetter;
}

Command::operator bool() const
{
    return !_actionClass.isEmpty();
}

} // namespace menu

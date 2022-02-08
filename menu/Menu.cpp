#include "Menu.h"
#include "Launcher.h"

#include <util/Factory.h>

#include <QDebug>

namespace menu {

const QString Menu::DEFAULT_COMMAND_TRANSLATOR_CLASS_NAME("menu::LineCommandTranslator");

potato_util::LazyPointer<menu::CommandTranslator> Menu::_commandTranslator(Menu::DEFAULT_COMMAND_TRANSLATOR_CLASS_NAME);

Menu::Menu(QObject *parent) : QObject(parent),
    _contextSetter(nullptr),
    _launcher(nullptr)
{

}

void Menu::registerCommand(const QString &cmd, const QString actionClass, ContextSetterPtr cntx)
{
    Command command(actionClass, cntx);
    _commands.insert(cmd, command);
}

void Menu::exec(const QString &command)
{
    auto commandInfo = Menu::_commandTranslator->translate(command);
    exec(commandInfo);
}

void Menu::addItem(const QString &command, const QString &actionClassName)
{
    _commandsOld.insert(command, actionClassName);
}

QList<QString> Menu::itemKeys() const
{
    return _commandsOld.keys();
}

Launcher *Menu::launcher() const
{
    return _launcher;
}

void Menu::setLauncher(Launcher *newLauncher)
{
    if (_launcher) {
        return;
    }

    _launcher = newLauncher;
    connect(_launcher, &Launcher::ready, this, &Menu::onResult);
}

ContextSetter *Menu::contextSetter() const
{
    return _contextSetter;
}

void Menu::setContextSetter(ContextSetter *contextSetter)
{
    _contextSetter = contextSetter;
}

void Menu::execOld(const CommandInfo &commandInfo)
{   
    QString actionClassName = _commandsOld.value(commandInfo.name(), QString());

    if (actionClassName.isEmpty()) {
        Error err;
        err.setCode(Error::NO_SUCH_ACTION_CLASS);
        err.addContext("className", commandInfo.name());
        emit error(err);
    }

    if (commandInfo.isNamedArgs()) {
        _launcher->launch(actionClassName, commandInfo.namedArgs(), _contextSetter);
    } else {
        _launcher->launch(actionClassName, commandInfo.args(), _contextSetter);
    }
}

void Menu::exec(const CommandInfo &commandInfo)
{
    Command command = _commands.value(commandInfo.name(), Command());

    if (!command) {
        Error err;
        err.setCode(Error::NO_SUCH_ACTION_CLASS);
        err.addContext("className", commandInfo.name());
        emit error(err);
    }

    if (commandInfo.isNamedArgs()) {
        _launcher->launch(command.actionClass(), commandInfo.namedArgs(), command.contextSetter().get());
    } else {
        _launcher->launch(command.actionClass(), commandInfo.args(), command.contextSetter().get());
    }
}

void Menu::onResult(const QVariant &value, const TaskId &taskId)
{
    qDebug() << "RESULT:" << value.toString();
    emit ready(value, taskId);
}

} // namespace menu

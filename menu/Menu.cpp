#include "Menu.h"
#include "Launcher.h"

#include <util/Factory.h>

#include <QDebug>

namespace menu {

const QString Menu::DEFAULT_COMMAND_TRANSLATOR_CLASS_NAME("menu::LineCommandTranslator");

potato_util::LazyPointer<menu::CommandTranslator> Menu::_commandTranslator(Menu::DEFAULT_COMMAND_TRANSLATOR_CLASS_NAME);

Menu::Menu(QObject *parent) : QObject(parent),
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

QList<QString> Menu::itemKeys() const
{
    return _commands.keys();
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

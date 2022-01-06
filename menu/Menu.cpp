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

void Menu::registerCommand(const QString &cmd, const QString actionClass)
{
    _commands.insert(cmd, actionClass);
}

void Menu::exec(const QString &command)
{
    auto commandInfo = Menu::_commandTranslator->translate(command);
    exec(commandInfo);
}

void Menu::addItem(const QString &command, const QString &actionClassName)
{
    _commands.insert(command, actionClassName);
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
    QString actionClassName = _commands.value(commandInfo.name());

    if (commandInfo.isNamedArgs()) {
        _launcher->launch(actionClassName, commandInfo.namedArgs());
    } else {
        _launcher->launch(actionClassName, commandInfo.args());
    }
}

void Menu::onResult(const QVariant &value)
{
    qDebug() << "RESULT:" << value.toString();
    emit ready(value);
}

} // namespace menu

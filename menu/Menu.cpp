#include "Menu.h"
#include "Launcher.h"

#include <util/Factory.h>

#include <QDebug>

namespace menu {

const QString Menu::DEFAULT_TASK_ID_GENERATOR_CLASS_NAME("uniq::TimeQStringValue");
const QString Menu::DEFAULT_COMMAND_TRANSLATOR_CLASS_NAME("menu::LineCommandTranslator");

potato_util::LazyPointer<uniq::Value<QString>> Menu::_taskIdGen(Menu::DEFAULT_TASK_ID_GENERATOR_CLASS_NAME);

potato_util::LazyPointer<menu::CommandTranslator> Menu::_commandTranslator(Menu::DEFAULT_COMMAND_TRANSLATOR_CLASS_NAME);

Menu::Menu(QObject *parent) : QObject(parent),
    _launcher(nullptr)
{

}

void Menu::registerCommand(const QString &itemKey, ActionPtr action)
{
    _items.insert(itemKey, action);
    //TODO: connect
}

void Menu::registerCommand(const QString &cmd, const QString actionClass)
{
    _commands.insert(cmd, actionClass);
}

void Menu::setTaskIdGenClassName(const QString &className)
{
    if (_taskIdGen) {
        return; //do not set if already exists
    }
    _taskIdGen.setClassName(className);
}

QString Menu::newTaskId()
{
    return _taskIdGen->value();
}

void Menu::exec(const QString &command)
{
    auto commandInfo = Menu::_commandTranslator->translate(command);
    exec(commandInfo);
}

void Menu::addItem(const QString &command, ActionPtr action)
{
    _items.insert(command, action);

    connect(action.get(), &Action::ready, this, &Menu::onTaskComplete);
}

void Menu::addItem(const QString &command, const QString &actionClassName)
{
    _commands.insert(command, actionClassName);
}

QList<QString> Menu::itemKeys() const
{
    return _items.keys();
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
    auto taskId = Menu::newTaskId();
    _pendingTasks.insert(taskId);
    QString commandName = commandInfo.name();
    auto action = _items.value(commandName);

    if (action) {
        if (commandInfo.isNamedArgs()) {
            action->act(commandInfo.namedArgs(), taskId);
        } else {
            action->act(commandInfo.args(), taskId);
        }
    } else {
        Error err;
        err.setCode(-1);
        err.setType(Error::ERROR_TYPE::MENU);
        err.setDescription(tr("no such a command"));
        QVariantMap mp;
        mp.insert(tr("command"), commandName);
        err.setContext(mp);
        emit error(err);
    }
}

void Menu::execAlt(const CommandInfo &commandInfo)
{
    QString actionClassName = _commands.value(commandInfo.name());

    if (commandInfo.isNamedArgs()) {
        _launcher->launch(actionClassName, commandInfo.namedArgs());
    } else {
        _launcher->launch(actionClassName, commandInfo.args());
    }
}

void Menu::onTaskComplete(const Result &result)
{
    auto taskId = result.taskId();

    if (_pendingTasks.contains(taskId)) {
        _pendingTasks.remove(taskId);

        if (result.errorCode() == Result::SUCCESSFUL_RESULT) {
            emit ready(result.value());
        } else {
            emit error(result.error());
        }


    }
}

void Menu::onResult(const QVariant &value)
{
    qDebug() << "RESULT:" << value.toString();
    emit ready(value);
}

} // namespace menu

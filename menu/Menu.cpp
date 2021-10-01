#include "Menu.h"

#include <util/Factory.h>

namespace menu {

const QString Menu::DEFAULT_TASK_ID_GENERATOR_CLASS_NAME("uniq::TimeQStringValue");
const QString Menu::DEFAULT_COMMAND_TRANSLATOR_CLASS_NAME("menu::LineCommandTranslator");

Menu::Menu(QObject *parent) : Menu(DEFAULT_TASK_ID_GENERATOR_CLASS_NAME,
                                   DEFAULT_COMMAND_TRANSLATOR_CLASS_NAME,
                                   parent)
{

}

Menu::Menu(const QString &taskIdGenClassName,
           const QString &commandTranslatorClassName,
           QObject *parent) :
    QObject(parent),
    _taskIdGen(taskIdGenClassName),
    _commandTranslator(commandTranslatorClassName)
{

}

void Menu::registerCommand(const QString &itemKey, ActionPtr action)
{
    _items.insert(itemKey, action);
    //TODO: connect
}

void Menu::setTaskIdGenClassName(const QString &className)
{
    _taskIdGen.setClassName(className);
}

QString Menu::newTaskId() const
{
    return _taskIdGen->value();
}

void Menu::exec(const QString &command)
{
    auto commandInfo = _commandTranslator->translate(command);
    exec(commandInfo);
}

void Menu::addItem(const QString &command, ActionPtr action)
{
    _items.insert(command, action);

    connect(action.get(), &Action::ready, this, &Menu::onTaskComplete);
}

QList<QString> Menu::itemKeys() const
{
    return _items.keys();
}

void Menu::exec(const CommandInfo &commandInfo)
{
    auto taskId = newTaskId();
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
        err.setDescription("no such a command");
        QVariantMap mp;
        mp.insert("action", commandName);
        err.setContext(mp);
        emit error(err);
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

} // namespace menu

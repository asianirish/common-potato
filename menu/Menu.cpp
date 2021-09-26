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

void Menu::exec(const QString &command) const
{
    auto commandInfo = _commandTranslator->translate(command);
    exec(commandInfo);
}

void Menu::exec(const CommandInfo &commandInfo) const
{
    auto taskId = newTaskId();
    QString commandName = commandInfo.name();
    auto action = _items.value(commandName);
    action->act(commandInfo.args(), taskId);
}

} // namespace menu

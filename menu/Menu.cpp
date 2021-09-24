#include "Menu.h"

#include <util/Factory.h>

namespace menu {

QString Menu::DEFAULT_TASK_ID_GENERATOR_CLASS_NAME("uniq::TimeQStringValue");

Menu::Menu(QObject *parent) : QObject(parent),
    _taskIdGeneratorClassName(DEFAULT_TASK_ID_GENERATOR_CLASS_NAME),
    _taskIdGenerator(nullptr)
{

}

void Menu::registerCommand(const QString &itemKey, ActionPtr action)
{
    _items.insert(itemKey, action);
    //TODO: connect
}

QString Menu::taskIdGeneratorClassName() const
{
    return _taskIdGeneratorClassName;
}

void Menu::setTaskIdGeneratorClassName(const QString &taskIdGeneratorClassName)
{
    _taskIdGeneratorClassName = taskIdGeneratorClassName;
}

uniq::Value<QString> *Menu::taskIdGenerator() const
{
    if (_taskIdGenerator == nullptr) {
        _taskIdGenerator = createTaskIdGenerator();
    }

    return _taskIdGenerator;
}

QString Menu::newTaskId() const
{
    return taskIdGenerator()->value();
}

uniq::Value<QString> *Menu::createTaskIdGenerator() const
{
    return util::Factory<uniq::Value<QString>>::create(_taskIdGeneratorClassName.toStdString());
}

} // namespace menu

#include "Menu.h"

namespace menu {

QString Menu::DEFAULT_TASK_ID_GENERATOR_CLASS_NAME("uniq::TimeQStringValue");

Menu::Menu(QObject *parent) : QObject(parent),
    _taskIdGeneratorClassName(DEFAULT_TASK_ID_GENERATOR_CLASS_NAME)
{

}

void Menu::registerAction(const QString &itemKey, ActionPtr action)
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

} // namespace menu

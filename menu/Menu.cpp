#include "Menu.h"

#include <util/Factory.h>

namespace menu {

QString Menu::DEFAULT_TASK_ID_GENERATOR_CLASS_NAME("uniq::TimeQStringValue");

Menu::Menu(QObject *parent) : QObject(parent),
    _taskIdGen(DEFAULT_TASK_ID_GENERATOR_CLASS_NAME)
{

}

void Menu::registerCommand(const QString &itemKey, ActionPtr action)
{
    _items.insert(itemKey, action);
    //TODO: connect
}

QString Menu::newTaskId() const
{
    return _taskIdGen->value();
}

} // namespace menu

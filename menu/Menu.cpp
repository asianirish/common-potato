#include "Menu.h"

namespace menu {

QString Menu::DEFAULT_TASK_ID_GENERATOR_CLASS_NAME("uniq::TimeQStringValue");

Menu::Menu(QObject *parent) : QObject(parent)
{

}

void Menu::registerAction(const QString &itemKey, ActionPtr action)
{
    _items.insert(itemKey, action);
    //TODO: connect
}

} // namespace menu

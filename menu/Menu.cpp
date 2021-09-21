#include "Menu.h"

namespace menu {

Menu::Menu(QObject *parent) : QObject(parent)
{

}

void Menu::registerAction(const QString &itemKey, ActionPtr action)
{
    _items.insert(itemKey, action);
    //TODO: connect
}

} // namespace menu

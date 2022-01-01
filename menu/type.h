#ifndef MENU_TYPE_H
#define MENU_TYPE_H

#include <QSharedPointer>

namespace menu {

class Action;
typedef QSharedPointer<Action> ActionPtr;

} // namespace menu

#endif // MENU_TYPE_H

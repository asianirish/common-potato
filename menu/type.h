#ifndef MENU_TYPE_H
#define MENU_TYPE_H

#include <QSharedPointer>

namespace menu {

class Action;
typedef QSharedPointer<Action> ActionPtr;

//TODO: TaskId class (?)
typedef QString TaskId;

} // namespace menu

#endif // MENU_TYPE_H

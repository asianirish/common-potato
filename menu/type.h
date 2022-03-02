#ifndef MENU_TYPE_H
#define MENU_TYPE_H

#include <QSharedPointer>
#include <QList>

namespace menu {

class Action;
typedef QSharedPointer<Action> ActionPtr;

//TODO: TaskId class (?)
typedef QString TaskId;

class ActionListener;
typedef QList<ActionListener *> Listeners;

} // namespace menu

#endif // MENU_TYPE_H

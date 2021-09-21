#ifndef MENU_MENU_H
#define MENU_MENU_H

#include "Action.h"

#include <QObject>
#include <QMap>
#include <QString>
#include <QSharedPointer>

namespace menu {

typedef QSharedPointer<Action> ActionPtr;

class Menu : public QObject
{
    Q_OBJECT
public:
    explicit Menu(QObject *parent=nullptr);

    void registerAction(const QString &itemKey, ActionPtr action);

signals:

private:
    QMap<QString, ActionPtr> _items;
};

} // namespace menu

#endif // MENU_MENU_H

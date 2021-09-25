#ifndef MENU_MENU_H
#define MENU_MENU_H

#include "Action.h"

#include <uniq/Value.h>
#include <util/LazyPointer.h>

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
    static QString DEFAULT_TASK_ID_GENERATOR_CLASS_NAME;

    explicit Menu(QObject *parent=nullptr);

    void registerCommand(const QString &itemKey, ActionPtr action);

    void setTaskIdGenClassName(const QString &className);

    QString newTaskId() const;

signals:

private:
    QMap<QString, ActionPtr> _items;
    util::LazyPointer<uniq::Value<QString>> _taskIdGen;


};

} // namespace menu

#endif // MENU_MENU_H

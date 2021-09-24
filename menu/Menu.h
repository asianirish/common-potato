#ifndef MENU_MENU_H
#define MENU_MENU_H

#include "Action.h"

#include <uniq/Value.h>

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

    QString taskIdGeneratorClassName() const;
    void setTaskIdGeneratorClassName(const QString &taskIdGeneratorClassName);

    uniq::Value<QString> *taskIdGenerator() const;

    QString newTaskId() const;

signals:

private:
    QMap<QString, ActionPtr> _items;
    QString _taskIdGeneratorClassName;
    mutable uniq::Value<QString> *_taskIdGenerator;

    uniq::Value<QString> *createTaskIdGenerator() const;
};

} // namespace menu

#endif // MENU_MENU_H

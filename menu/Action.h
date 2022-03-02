#ifndef MENU_ACTION_H
#define MENU_ACTION_H

#include "Result.h"
#include "def/ActionDef.h"

#include <QObject>
#include <QVariantList>

namespace menu {

class ActionListener;

class Action : public QObject
{
    Q_OBJECT
public:
    explicit Action(QObject *parent = nullptr);

    void act(const QVariantList &args, const TaskId &taskId);

    void act(const QVariantMap &namedArgs, const TaskId &taskId);

    void toPositionalArguments(const QVariantMap &namedArgs, QVariantList &posArgs);

signals:
    void ready(const menu::Result &result);

private:
    virtual void actSpecific(const QVariantList &args, const TaskId &taskId) = 0;

    virtual def::ActionDef actionDef() const = 0;

};

typedef QSharedPointer<Action> ActionPtr;

} // namespace menu

#endif // MENU_ACTION_H

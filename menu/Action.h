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

    void act(const QVariantList &args, const TaskId &taskId, const Listeners &listeners = Listeners());

    void act(const QVariantMap &namedArgs, const TaskId &taskId, const Listeners &listeners = Listeners());

    void toPositionalArguments(const QVariantMap &namedArgs, QVariantList &posArgs);

private:
    int _listenerNum;

signals:
    void done(const menu::Result &result);

    void complete(const menu::Result &result);

private slots:
    void emitCompleteDebug(const menu::Result &result);

private:
    virtual void actSpecific(const QVariantList &args, const TaskId &taskId) = 0;

    virtual def::ActionDef actionDef() const = 0;

private slots:
    void onListenerHandled(const menu::Result &result);

};

typedef QSharedPointer<Action> ActionPtr;

} // namespace menu

#endif // MENU_ACTION_H

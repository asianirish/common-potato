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

    Result act(const QVariantList &args, const TaskId &taskId = TaskId(), const Listeners &listeners = Listeners());

    Result act(const QVariantMap &namedArgs, const TaskId &taskId = TaskId(), const Listeners &listeners = Listeners());

    void toPositionalArguments(const QVariantMap &namedArgs, QVariantList &posArgs);

    //used in ACTION_CLASS_NAME
    static QString checkActionClass(const QString &actionClassName) {
        return actionClassName;
    }

private:
    int _listenerNum;

signals:
    void done(const menu::Result &result);

    void allListenersComplete(const menu::Result &result);

private slots:
    void emitCompleteDebug(const menu::Result &result);

private:
    virtual Result actSpecific(const QVariantList &args, const TaskId &taskId) = 0;

    virtual def::ActionDef actionDef() const = 0;

private slots:
    void onListenerHandled(const menu::Result &result);

};

typedef QSharedPointer<Action> ActionPtr;

} // namespace menu

#define ACTION_CLASS(className) className::checkActionClass(#className)

#endif // MENU_ACTION_H

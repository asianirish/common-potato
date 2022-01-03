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

    void act(const QVariantList &args, const QString &taskId, ActionListener *listener = nullptr);

    void act(const QVariantMap &namedArgs, const QString &taskId, ActionListener *listener = nullptr);

    void toPositionalArguments(const QVariantMap &namedArgs, QVariantList &posArgs);

signals:
    void ready(const menu::Result &result);

private:
    virtual void actSpecific(const QVariantList &args, const QString &taskId) = 0;

    virtual def::ActionDef actionDef() const = 0;

};

} // namespace menu

#endif // MENU_ACTION_H

#ifndef MENU_ACTION_H
#define MENU_ACTION_H

#include "Result.h"
#include "def/ActionDef.h"

#include <QObject>
#include <QVariantList>

namespace menu {

class Action : public QObject
{
    Q_OBJECT
public:
    explicit Action(QObject *parent = nullptr);

    void act(const QVariantList &args, const QString &taskId);

    virtual const char *alias() const = 0;

signals:
    void ready(const Result &result);

private:
    virtual void actSpecific(const QVariantList &args, const QString &taskId) = 0;

    [[deprecated]]
    virtual QList<def::ActionDef> defs() const = 0;

    virtual def::ActionDef actionDef() const = 0;


};

} // namespace menu

#endif // MENU_ACTION_H

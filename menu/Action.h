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

    virtual void act(const QVariantList &args, const QString &taskId) = 0;

    virtual const char *alias() const = 0;

    void addDef(const def::ActionDef &actionDef);

signals:
    void ready(const Result &result);

private:
    QList<def::ActionDef> _defs;

};

} // namespace menu

#endif // MENU_ACTION_H

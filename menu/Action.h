#ifndef MENU_ACTION_H
#define MENU_ACTION_H

#include <QObject>
#include <QVariantList>

namespace menu {

class Action : public QObject
{
    Q_OBJECT
public:
    explicit Action(QObject *parent = nullptr);

    virtual void act(const QVariantList &args) = 0;

    virtual const char *alias() const = 0;

signals:
    void ready(const QVariant &result);

};

} // namespace menu

#endif // MENU_ACTION_H

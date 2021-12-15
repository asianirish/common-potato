#ifndef HIERHIN_NAV_STEP_H
#define HIERHIN_NAV_STEP_H

#include <hierhin/type.h>

namespace hierhin {
namespace nav {

class Step
{
public:
    enum Action {
        PARENT,
        CHILD_ROLE,
        CHILD_ID,
        ROOT
    };

    Step();

    Action action() const;
    void setAction(Action newAction);

    const QString &arg() const;
    void setArg(const QString &newArg);

    Item *go(Item *item) const;

private:
    Action _action;
    QString _arg; //Id or Role
};

} // namespace nav
} // namespace hierhin

#endif // HIERHIN_NAV_STEP_H

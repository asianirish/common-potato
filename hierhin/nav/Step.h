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

    Step(const QString &str);

    Step(const char *str);

    Action action() const;
    void setAction(Action newAction);

    const QString &arg() const;
    void setArg(const QString &newArg);

    ItemWeakPtr go(ItemPtr item) const;

    QString toString() const;

    void fromString(const QString &str);

    Step &operator=(const QString &str);

    Step &operator=(const char *str);

    operator QString() const;

private:
    Action _action;
    QString _arg; //Id or Role

    QString actionToString() const;
    void stringToAction(const QString &str);
};

} // namespace nav
} // namespace hierhin

#endif // HIERHIN_NAV_STEP_H

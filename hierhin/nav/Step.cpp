#include "Step.h"
#include <hierhin/Node.h>

namespace hierhin {
namespace nav {

Step::Step() : _action(PARENT) //TODO: UNDEFINED (?)
{

}

Step::Step(const QString &str)
{
    fromString(str);
}

Step::Step(const char *str) : Step(QString(str))
{

}

Step::Action Step::action() const
{
    return _action;
}

void Step::setAction(Action newAction)
{
    _action = newAction;
}

const QString &Step::arg() const
{
    return _arg;
}

void Step::setArg(const QString &newArg)
{
    _arg = newArg;
}

ItemWeakPtr Step::go(Item *item) const
{
    Node *node = dynamic_cast<Node *>(item);

    switch (_action) {
    case PARENT:
        return item->parentNode();
    case CHILD_ID:
        if (node) {
            return node->child(_arg).toWeakRef();
        }

        break;

    case CHILD_ROLE:
        if (node) {
            return node->childByRole(_arg).toWeakRef();
        }

        break;

    case ROOT:
        ; //TODO: get root
    }

    return {};
}

QString Step::toString() const
{
    return actionToString() + ":" + _arg;
}

void Step::fromString(const QString &str)
{
    auto lst = str.split(":");
    stringToAction(lst.at(0));

    if (lst.size() > 1) {
        _arg = lst.at(1);
    }
}

Step &Step::operator=(const QString &str)
{
    fromString(str);
    return *this;
}

QString Step::actionToString() const
{
    switch (_action) {

    case PARENT:
        return QString("PARENT");

    case CHILD_ID:
        return QString("CHILD_ID");

    case CHILD_ROLE:
        return QString("CHILD_ROLE");

    case ROOT:
        return QString("CHILD_ROLE");
    }

    return {};
}

void Step::stringToAction(const QString &str)
{
    if (str == "PARENT") {
        setAction(PARENT);
    } else if (str == "CHILD_ID") {
        setAction(CHILD_ID);
    } else if (str == "CHILD_ROLE") {
        setAction(CHILD_ROLE);
    } else if (str == "ROOT") {
        setAction(ROOT);
    }
}

} // namespace nav
} // namespace hierhin

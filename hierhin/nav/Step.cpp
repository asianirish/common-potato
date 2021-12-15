#include "Step.h"
#include <hierhin/Node.h>

namespace hierhin {
namespace nav {

Step::Step()
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

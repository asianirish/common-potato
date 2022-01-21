#include "Step.h"
#include <hierhin/Node.h>

namespace hierhin {
namespace nav {

Step::Step() : Step(QString())
{

}

Step::Step(const QString &str): _action(UNDEFINED)
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

ItemPtr Step::go(ItemPtr item)
{
    ConstItemPtr constItem = item.staticCast<const Item>();
    return go(constItem).constCast<Item>();
}

ConstItemPtr Step::go(ConstItemPtr item) const
{
    ConstNodePtr node = item.dynamicCast<const Node>();

    switch (_action) {
    case UNDEFINED:
        return item;
    case PARENT:
        return item->parentNode();
    case CHILD_ID:
        if (node) {
            return node->child(_arg);
        }

        break;
    case CHILD_NAME:
        if (node) {
            return node->childByName(_arg);
        }

        break;
    case CHILD_ROLE:
        if (node) {
            return node->childByRole(_arg);
        }

        break;

    case ROOT:
        return goRoot(item);
    }

    return {};
}

QString Step::toString() const
{
    if (_action == PARENT || _action == ROOT || _action == UNDEFINED) {
        return actionToString();
    }

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

Step::operator QString() const
{
    return toString();
}

Step &Step::operator=(const char *str)
{
    fromString(QString(str));
    return *this;
}

QString Step::actionToString() const
{
    switch (_action) {

    case UNDEFINED:
        return QString(".");

    case PARENT:
        return QString("..");

    case CHILD_ID:
        return QString("CHILD_ID");

    case CHILD_ROLE:
        return QString("CHILD_ROLE");

    case ROOT:
        return QString();
    }

    return {};
}

void Step::stringToAction(const QString &str)
{
    if (str == ".") {
        setAction(UNDEFINED);
    } if (str == "..") {
        setAction(PARENT);
    } else if (str == "CHILD_ID") {
        setAction(CHILD_ID);
    } else if (str == "CHILD_ROLE") {
        setAction(CHILD_ROLE);
    } else if (str.isEmpty() || str == "/") {
        setAction(ROOT);
    }
}

ItemPtr Step::goRoot(ItemPtr item)
{
    ConstItemPtr constItem = item.staticCast<const Item>();
    return goRoot(constItem).constCast<Item>();
}

ConstItemPtr Step::goRoot(ConstItemPtr item) const
{
    ConstItemPtr curItem = item;

    while (1) {
        auto tmpItem = curItem->parentNode();

        if (!tmpItem) {
            //the first parentless is the root
            return curItem;
        }
        curItem = tmpItem.lock();
    }
}

} // namespace nav
} // namespace hierhin

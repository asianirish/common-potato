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

    case CHILD_ROLE:
        if (node) {
            return node->childByRole(_arg).toWeakRef();
        }
    case ROOT:
        ; //TODO: get root
    }
}

} // namespace nav
} // namespace hierhin

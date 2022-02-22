#include "CallChildren.h"
#include "../Node.h"

namespace hierhin {
namespace sys {

CallChildren::CallChildren()
{

}

bool CallChildren::isSync() const
{
    return false;
}

menu::def::ActionDef CallChildren::actionDef() const
{
    menu::def::ActionDef def;
    def.setArgMinNum(1);

    return def;
}

QVariant CallChildren::actNodeImpl(const QVariantList &args, Node *node)
{
    auto children = node->children();
    _innerArgs = args;
    auto innerMethod = _innerArgs.takeFirst().toString();

    for (auto &child : children) {
        child->execute(innerMethod, _innerArgs);
    }


    //TODO: what to return?
    return true;
}

void CallChildren::onChildReady(const menu::TaskId &taskId)
{
    //TODO: implement
    //...
//    Result result;
//    result.setTaskId(_taskId);
//TODO:    emit ready(result);
}

} // namespace sys
} // namespace hierhin

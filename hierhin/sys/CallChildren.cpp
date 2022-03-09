#include "CallChildren.h"
#include "../Node.h"
#include "menu/Redirector.h"

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
        menu::TaskId taskId = menu::TaskInfo::genTaskId();
        _taskIdToNode.insert(taskId, child);
    }

    auto ids = _taskIdToNode.keys();
    for (auto &taskId : ids) {
        menu::ActionListener *listener = new menu::Redirector(this);
        //TODO: connect the listener
        menu::TaskInfo taskInfo(taskId, {listener});
        auto child = _taskIdToNode.value(taskId);

        child->execute(innerMethod, _innerArgs, taskInfo);
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

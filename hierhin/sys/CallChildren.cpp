#include "CallChildren.h"
#include "../Node.h"
#include "menu/Redirector.h"

#include <QDebug>

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

QVariant CallChildren::actNodeImpl(const QVariantList &args, Node *node, const menu::TaskId &taskId)
{
    _taskId = taskId;
    auto children = node->children();
    auto innerArgs = args;
    auto innerMethod = innerArgs.takeFirst().toString();

    if (!innerArgs.isEmpty()) {
        _foldMethodName = innerArgs.takeFirst().toString();
    }

    for (auto &child : children) {
        menu::TaskId taskId = menu::TaskInfo::genTaskId();
        _taskIdToNode.insert(taskId, child);
    }

    auto ids = _taskIdToNode.keys();
    for (auto &taskId : ids) {
        menu::ActionListener *listener = new menu::Redirector(this);
        connect(listener, &menu::ActionListener::handled, this, &CallChildren::onChildReady);
        menu::TaskInfo taskInfo(taskId, {listener});
        auto child = _taskIdToNode.value(taskId);

        child->execute(innerMethod, innerArgs, taskInfo);
    }

    //TODO: what to return?
    return true;
}

void CallChildren::onChildReady(const menu::Result &childResult)
{
    auto taskId = childResult.taskId();
    auto item = _taskIdToNode.take(taskId);

    qDebug() << "CHILD IS READY CHILD_ID:" << item->id() << "TASK_ID:" << taskId;

    if (_taskIdToNode.isEmpty()) {
        if (_foldMethodName.isEmpty()) {
            menu::Result result;
            result.setTaskId(_taskId);
            emit done(result);
        } else {
            //TODO: launch _foldMethodName
            //...
        }

    }
}

} // namespace sys
} // namespace hierhin

#include "TaskInfo.h"

namespace menu {

const QString TaskInfo::DEFAULT_ACTION_ID_GENERATOR_CLASS_NAME("uniq::TimeQStringValue");

TaskInfo::TaskInfo()
{

}

TaskInfo::TaskInfo(TaskId &taskId, const Listeners &listeners) : _listeners(listeners)
{
    if (taskId.isEmpty()) {
        _taskId = genTaskId();
        taskId = _taskId;
    } else {
        _taskId = taskId;
    }
}

const TaskId &TaskInfo::taskId() const
{
    return _taskId;
}

const Listeners &TaskInfo::listeners() const
{
    return _listeners;
}

TaskId TaskInfo::genTaskId() const
{
    //TODO: implement
    return TaskId();
}

} // namespace menu

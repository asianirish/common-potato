#include "TaskInfo.h"

namespace menu {

const QString TaskInfo::DEFAULT_ACTION_ID_GENERATOR_CLASS_NAME("uniq::TimeQStringValue");

potato_util::LazyPointer<uniq::Value<QString>> TaskInfo::_taskIdGen(TaskInfo::DEFAULT_ACTION_ID_GENERATOR_CLASS_NAME);

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

void TaskInfo::setTaskIdGenClassName(const QString &className)
{
    _taskIdGen.setClassName(className);
}

TaskId TaskInfo::genTaskId() const
{
    return _taskIdGen->value();
}

} // namespace menu

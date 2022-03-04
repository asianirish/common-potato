#ifndef MENU_TASKINFO_H
#define MENU_TASKINFO_H

#include "type.h"

#include <util/LazyPointer.h>
#include <uniq/Value.h>

namespace menu {

class TaskInfo
{
public:
    static const QString DEFAULT_ACTION_ID_GENERATOR_CLASS_NAME;

    TaskInfo();
    TaskInfo(TaskId &taskId, const Listeners &listeners);
    TaskInfo(TaskId *taskId, const Listeners &listeners);

    const TaskId &taskId() const;

    const Listeners &listeners() const;

    static void setTaskIdGenClassName(const QString &className);

private:
    TaskId _taskId;
    Listeners _listeners;

    //TODO: use QString as generated value but convert to TaskId
    static potato_util::LazyPointer<uniq::Value<QString>> _taskIdGen;

    TaskId genTaskId() const;
};

} // namespace menu

#endif // MENU_TASKINFO_H

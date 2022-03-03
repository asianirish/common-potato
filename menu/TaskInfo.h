#ifndef MENU_TASKINFO_H
#define MENU_TASKINFO_H

#include "type.h"

namespace menu {

class TaskInfo
{
public:
    TaskInfo();
    TaskInfo(TaskId &taskId, const Listeners &listeners);

private:
    TaskId _taskId;
    Listeners _listeners;

    TaskId genTaskId() const;
};

} // namespace menu

#endif // MENU_TASKINFO_H

#include "Fold.h"
#include "SyncLauncher.h"

namespace menu {
namespace hof {

Fold::Fold()
{

}

QVariant Fold::simplyAct(const QVariantList &args, const TaskId &taskId)
{
    QString accFunc = args.at(0).toString();
    _acc = args.at(1);
    _taskId = taskId;

//    Launcher *launcher = new SyncLauncher(this);
//    launcher

    return QVariant();//not for use
}

bool Fold::isSync() const
{
    return false;
}

def::ActionDef Fold::actionDef() const
{
    //acc function, startValue, lst, <args of the acc function>
    def::ActionDef actionDef;
    actionDef.setArgMinNum(3);

    //TODO: add arg defs

    return actionDef;
}

} // namespace hof
} // namespace menu

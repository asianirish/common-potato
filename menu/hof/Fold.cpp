#include "Fold.h"
#include "SyncLauncher.h"

namespace menu {
namespace hof {

Fold::Fold() : _launcher(new SyncLauncher(this))
{

}

QVariant Fold::simplyAct(const QVariantList &args)
{
    QString accFunc = args.at(0).toString();
    _acc = args.at(1);
//    _taskId = taskId;

    TaskInfo info;
    //TODO: set listeners
//    info.setTaskIdGenClassName()


    //TODO: sync code instead of this:
    _launcher->launch(accFunc, {_acc}, ContextSetterPtr(), info);

    return QVariant();//not for use
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

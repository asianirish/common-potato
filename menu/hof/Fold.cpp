#include "Fold.h"
#include "SyncLauncher.h"

namespace menu {
namespace hof {

Fold::Fold() : _launcher(new SyncLauncher(this))
{

}

QVariant Fold::simplyAct(const QVariantList &args)
{
    auto innerArgs = args;
    QString combFunc = innerArgs.takeFirst().toString();
    QVariant startValue = innerArgs.takeFirst();
    QVariant result = startValue;

    for (auto &curValue : innerArgs) {
        result = SimpleAction::simpleAct(combFunc, {result, curValue});
    }

    return result;
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

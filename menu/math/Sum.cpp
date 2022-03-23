#include "Sum.h"

namespace menu {
namespace math {

Sum::Sum()
{

}

QVariant Sum::simplyAct(const QVariantList &args)
{
    return args.at(0).toDouble() + args.at(1).toDouble();
}

def::ActionDef Sum::actionDef() const
{
    def::ActionDef actionDef;
    actionDef.setArgMinNum(2);
    actionDef.setArgMaxNum(2);

    return actionDef;
}

} // namespace math
} // namespace menu

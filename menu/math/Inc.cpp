#include "Inc.h"

namespace menu {
namespace math {

Inc::Inc()
{

}

const char *Inc::alias() const
{
    return "inc";
}

QVariant Inc::simplyAct(const QVariantList &args)
{
    return args.at(0).toInt() + 1;
}

QList<def::ActionDef> Inc::defs() const
{
    def::ActionDef adf;
    adf.setArgMinNum(1);
    adf.setArgMaxNum(1);

    return {adf};
}

} // namespace math
} // namespace menu

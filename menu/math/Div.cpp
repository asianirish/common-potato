#include "Div.h"

namespace menu {
namespace math {

Div::Div()
{

}

QVariant Div::simplyAct(const QVariantList &args)
{
    //TODO: check arg num & divide by zero;
    return args.at(0).toFloat() / args.at(1).toFloat();

}

QList<def::ActionDef> Div::defs() const
{
    def::ActionDef adf;
    adf.setArgMinNum(2);
    adf.setArgMaxNum(2);

    return {adf};
}

def::ActionDef Div::actionDef() const
{
    def::ActionDef adf;
    adf.setArgMinNum(2);
    adf.setArgMaxNum(2);

    return adf;
}

} // namespace math
} // namespace menu

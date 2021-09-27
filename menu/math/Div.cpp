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

} // namespace math
} // namespace menu

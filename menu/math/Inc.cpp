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

} // namespace math
} // namespace menu

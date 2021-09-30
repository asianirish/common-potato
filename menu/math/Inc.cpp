#include "Inc.h"
#include "def/NotEqualConstraint.h"

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

def::ActionDef Inc::actionDef() const
{
    QSharedPointer<def::Constraint> notEq(new def::NotEqualConstraint());
    notEq.dynamicCast<def::NotEqualConstraint>()->setValue(-1);

    def::ArgDef argDef;
    argDef.setDefaultValue(12);
    argDef.addConstraint(notEq);

    def::ActionDef actionDef;
    actionDef.setArgMinNum(1);
    actionDef.setArgMaxNum(1);
    actionDef.addArgDef(argDef);

    return actionDef;
}

} // namespace math
} // namespace menu

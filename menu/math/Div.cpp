#include "Div.h"
#include "def/NotEqualConstraint.h"

namespace menu {
namespace math {

Div::Div()
{

}

QVariant Div::simplyAct(const QVariantList &args)
{
    return args.at(0).toDouble() / args.at(1).toDouble();
}

def::ActionDef Div::actionDef() const
{
    QSharedPointer<def::Constraint> notEq(new def::NotEqualConstraint());
    notEq.dynamicCast<def::NotEqualConstraint>()->setValue(0);

    def::ArgDef argDef;
    argDef.setDefaultValue(1);
    argDef.addConstraint(notEq);

    def::ActionDef actionDef;
    actionDef.setArgMinNum(2);
    actionDef.setArgMaxNum(2);
    actionDef.insertArgDef(1, argDef);

    return actionDef;
}

} // namespace math
} // namespace menu

#include "LinkedEssence.h"

namespace hierhin {
namespace def {

LinkedEssence::LinkedEssence()
{

}

QMap<QString, MethodDef> LinkedEssence::commandDefs() const
{
    auto mp = Essence::commandDefs();

    ArgDef linkTargetArgDef;
    linkTargetArgDef.setName("target");
//TODO:    linkTargetArgDef.addValidator()
    MethodDef linkCommandDef("link", {linkTargetArgDef});
    mp.insert("link", linkCommandDef);

    return mp;
}

void LinkedEssence::linkItem(Item *item, const nav::ItemRef &iRef) const
{
    //TODO: implement
    Q_UNUSED(item)
    Q_UNUSED(iRef)
}

} // namespace def
} // namespace hierhin

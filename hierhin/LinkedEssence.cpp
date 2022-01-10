#include "LinkedEssence.h"

namespace hierhin {
namespace def {

LinkedEssence::LinkedEssence()
{

}

QMap<QString, MethodDef> LinkedEssence::methodDefs() const
{
    auto mp = Essence::methodDefs();

    ArgDef linkTargetArgDef;
    linkTargetArgDef.setName("target");
//TODO:    linkTargetArgDef.addValidator()
    MethodDef linkCommandDef("link", {linkTargetArgDef});
    mp.insert("link", linkCommandDef);

    return mp;
}

QStringList LinkedEssence::methodNames() const
{
    QStringList lst = Essence::methodNames();
    //TODO: add a sys::Link action
    return lst;
}

void LinkedEssence::linkItem(Item *item, const nav::ItemRef &iRef) const
{
    //TODO: implement
    Q_UNUSED(item)
    Q_UNUSED(iRef)
}

} // namespace def
} // namespace hierhin

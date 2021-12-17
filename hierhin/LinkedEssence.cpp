#include "LinkedEssence.h"

namespace hierhin {
namespace def {

LinkedEssence::LinkedEssence()
{

}

void LinkedEssence::executeImpl(Item *item, const QString &command, const QVariantList &args) const
{
    if (command == "link") { //TODO: const
        nav::ItemRef iRef = args.at(0).value<nav::ItemRef>();
        linkItem(item, iRef);
        return;
    }

    executeLinkedEssence(item, command, args);
}

QMap<QString, CommandDef> LinkedEssence::commandDefs() const
{
    auto mp = Essence::commandDefs();

    ArgDef linkTargetArgDef;
    linkTargetArgDef.setName("target");
//TODO:    linkTargetArgDef.addValidator()
    CommandDef linkCommandDef("link", {linkTargetArgDef});
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

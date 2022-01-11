#include "LinkedEssence.h"

namespace hierhin {

LinkedEssence::LinkedEssence()
{

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

} // namespace hierhin

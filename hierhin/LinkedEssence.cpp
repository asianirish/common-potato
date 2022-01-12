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


} // namespace hierhin

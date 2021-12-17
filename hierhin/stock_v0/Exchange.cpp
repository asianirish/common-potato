#include "Exchange.h"

namespace stock_v0 {

Exchange::Exchange()
{

}

NodeDef Exchange::nodeDef() const
{
    //TODO: implement
    return NodeDef();
}

void Exchange::executeImpl(Item *item, const QString &command, const QVariantList &args) const
{
    //TODO: implement
    Q_UNUSED(item)
    Q_UNUSED(command)
    Q_UNUSED(args)

}

} // namespace stock_v0

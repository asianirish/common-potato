#include "GetClassName.h"

namespace hierhin {
namespace sys {

GetClassName::GetClassName()
{

}

QVariant GetClassName::actImpl(const QVariantList &args, Item *item)
{
    Q_UNUSED(args)
    return item->essenceClassName();
}

} // namespace sys
} // namespace hierhin

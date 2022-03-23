#include "GetMethodNames.h"

namespace hierhin {
namespace sys {

GetMethodNames::GetMethodNames()
{

}

QVariant GetMethodNames::actImpl(const QVariantList &args, Item *item)
{
    Q_UNUSED(args)
    return item->essenceMethodNames();
}

} // namespace sys
} // namespace hierhin

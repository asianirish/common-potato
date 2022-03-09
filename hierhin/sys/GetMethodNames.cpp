#include "GetMethodNames.h"

namespace hierhin {
namespace sys {

GetMethodNames::GetMethodNames()
{

}

QVariant GetMethodNames::actImpl(const QVariantList &args, Item *item, const menu::TaskId &taskId)
{
    Q_UNUSED(args)
    return item->essenceMethodNames();
}

} // namespace sys
} // namespace hierhin

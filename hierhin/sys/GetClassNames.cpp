#include "GetClassNames.h"

namespace hierhin {
namespace sys {

GetClassNames::GetClassNames()
{

}

QVariant GetClassNames::actImpl(const QVariantList &args, Item *item, const menu::TaskId &taskId)
{
    Q_UNUSED(args)
    return item->essenceClassNames();
}

} // namespace sys
} // namespace hierhin

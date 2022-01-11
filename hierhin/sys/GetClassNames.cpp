#include "GetClassNames.h"

namespace hierhin {
namespace sys {

GetClassNames::GetClassNames()
{

}

QVariant GetClassNames::actImpl(const QVariantList &args, Item *item)
{
    Q_UNUSED(args)
    return item->essenceClassNames();
}

} // namespace sys
} // namespace hierhin

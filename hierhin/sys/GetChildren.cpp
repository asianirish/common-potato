#include "GetChildren.h"
#include "Node.h"

namespace hierhin {
namespace sys {

GetChildren::GetChildren()
{

}

QVariant GetChildren::actNodeImpl(const QVariantList &args, Node *node, const menu::TaskId &taskId)
{
    Q_UNUSED(args);

    return QVariant::fromValue(node->childRefs());
}

} // namespace sys
} // namespace hierhin

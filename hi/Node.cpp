#include "Node.h"

namespace hi {

Node::Node(QObject *parent) : Item(parent)
{

}

void Node::toMapNodeSpecific(QVariantMap &mp) const
{
    //TODO: implement (write children)
    Q_UNUSED(mp);
}

} // namespace hi

#include "NotANode.h"

namespace hierhin {
namespace ex {

NotANode::NotANode() : NotANode(Id())
{

}

NotANode::NotANode(const Id &id) : _id(id)
{

}

const Id &NotANode::id() const
{
    return _id;
}

void NotANode::setId(const Id &newId)
{
    _id = newId;
}

} // namespace ex
} // namespace hierhin

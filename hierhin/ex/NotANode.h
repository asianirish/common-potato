#ifndef HIERHIN_EX_NOTANODE_H
#define HIERHIN_EX_NOTANODE_H

#include "Exception.h"
#include "../type.h"

namespace hierhin {
namespace ex {

class NotANode : public Exception
{
public:
    NotANode();
    NotANode(const Id &id);

    const Id &id() const;
    void setId(const Id &newId);

    QString cause() const override {
        return tr("item is not a node: '%1'").arg(id());
    }

private:
    Id _id;
};

} // namespace ex
} // namespace hierhin

#endif // HIERHIN_EX_NOTANODE_H

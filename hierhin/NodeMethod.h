#ifndef HIERHIN_NODEMETHOD_H
#define HIERHIN_NODEMETHOD_H

#include "Method.h"

namespace hierhin {

class NodeMethod : public Method
{
public:
    NodeMethod();

private:
    QVariant actImpl(const QVariantList &args, Item *item) final;

    virtual QVariant actNodeImpl(const QVariantList &args, Node *node) = 0;
};

} // namespace hierhin

#endif // HIERHIN_NODEMETHOD_H

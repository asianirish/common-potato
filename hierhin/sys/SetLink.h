#ifndef HIERHIN_SYS_SETLINK_H
#define HIERHIN_SYS_SETLINK_H

#include <NodeMethod.h>

namespace hierhin {
namespace sys {

class SetLink : public NodeMethod
{
public:
    SetLink();

private:
    menu::def::ActionDef actionDef() const override;

private:
    QVariant actNodeImpl(const QVariantList &args, Node *node) override;
};

} // namespace sys
} // namespace hierhin

#endif // HIERHIN_SYS_SETLINK_H

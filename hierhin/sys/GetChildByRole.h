#ifndef HIERHIN_SYS_GETCHILDBYROLE_H
#define HIERHIN_SYS_GETCHILDBYROLE_H

#include <NodeMethod.h>

namespace hierhin {
namespace sys {

class GetChildByRole : public NodeMethod
{
public:
    GetChildByRole();

private:
    menu::def::ActionDef actionDef() const override;
private:
    QVariant actNodeImpl(const QVariantList &args, Node *node) override;
};

} // namespace sys
} // namespace hierhin

#endif // HIERHIN_SYS_GETCHILDBYROLE_H

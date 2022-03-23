#ifndef HIERHIN_SYS_GETCHILDREN_H
#define HIERHIN_SYS_GETCHILDREN_H

#include <NodeMethod.h>

namespace hierhin {
namespace sys {

class GetChildren : public NodeMethod
{
public:
    GetChildren();

private:
    menu::def::ActionDef actionDef() const override {
        return menu::def::ActionDef();
    }

private:
    QVariant actNodeImpl(const QVariantList &args, Node *node) override;
};

} // namespace sys
} // namespace hierhin

#endif // HIERHIN_SYS_GETCHILDREN_H

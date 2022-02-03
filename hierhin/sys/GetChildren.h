#ifndef HIERHIN_SYS_GETCHILDREN_H
#define HIERHIN_SYS_GETCHILDREN_H

#include <Method.h>

namespace hierhin {
namespace sys {

//TODO: from NodeMethod
class GetChildren : public hierhin::Method
{
public:
    GetChildren();

private:
    menu::def::ActionDef actionDef() const override {
        return menu::def::ActionDef();
    }

private:
    QVariant actImpl(const QVariantList &args, Item *item) override;
};

} // namespace sys
} // namespace hierhin

#endif // HIERHIN_SYS_GETCHILDREN_H

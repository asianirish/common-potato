#ifndef HIERHIN_SYS_GETNAME_H
#define HIERHIN_SYS_GETNAME_H

#include <ItemAction.h>

namespace hierhin {
namespace sys {

class GetName : public hierhin::ItemAction
{
public:
    GetName();

private:
    menu::def::ActionDef actionDef() const override;

private:
    QVariant actImpl(const QVariantList &args, Item *item) override;
};

} // namespace sys
} // namespace hierhin

#endif // HIERHIN_SYS_GETNAME_H

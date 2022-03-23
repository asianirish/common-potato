#ifndef HIERHIN_SYS_GETNAME_H
#define HIERHIN_SYS_GETNAME_H

#include <Method.h>

namespace hierhin {
namespace sys {

class GetName : public hierhin::Method
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

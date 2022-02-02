#ifndef HIERHIN_SYS_SETLINK_H
#define HIERHIN_SYS_SETLINK_H

#include <Method.h>

namespace hierhin {
namespace sys {

class SetLink : public hierhin::Method
{
public:
    SetLink();

private:
    menu::def::ActionDef actionDef() const override;

private:
    QVariant actImpl(const QVariantList &args, Item *item) override;
};

} // namespace sys
} // namespace hierhin

#endif // HIERHIN_SYS_SETLINK_H

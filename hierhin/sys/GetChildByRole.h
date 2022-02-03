#ifndef HIERHIN_SYS_GETCHILDBYROLE_H
#define HIERHIN_SYS_GETCHILDBYROLE_H

#include <Method.h>

namespace hierhin {
namespace sys {

//TODO: from NodeMethod
class GetChildByRole : public hierhin::Method
{
public:
    GetChildByRole();

private:
    menu::def::ActionDef actionDef() const override;
private:
    QVariant actImpl(const QVariantList &args, Item *item) override;
};

} // namespace sys
} // namespace hierhin

#endif // HIERHIN_SYS_GETCHILDBYROLE_H

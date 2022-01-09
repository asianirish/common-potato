#ifndef SYS_GETPROPERTY_H
#define SYS_GETPROPERTY_H

#include <ItemAction.h>

namespace hierhin {
namespace sys {

class GetProperty : public hierhin::ItemAction
{
public:
    GetProperty();

private:
    menu::def::ActionDef actionDef() const override;

private:
    QVariant actImpl(const QVariantList &args, Item *item) override;
};

} // namespace sys
} // namespace hierhin

#endif // SYS_GETPROPERTY_H

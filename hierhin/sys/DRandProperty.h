#ifndef HIERHIN_SYS_DRANDPROPERTY_H
#define HIERHIN_SYS_DRANDPROPERTY_H

#include <Method.h>

namespace hierhin {
namespace sys {

class DRandProperty : public hierhin::Method
{
public:
    DRandProperty();

private:
    menu::def::ActionDef actionDef() const override;

private:
    QVariant actImpl(const QVariantList &args, Item *item) override;
};

} // namespace sys
} // namespace hierhin

#endif // HIERHIN_SYS_DRANDPROPERTY_H

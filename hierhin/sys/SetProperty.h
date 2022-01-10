#ifndef SETPROPERTY_H
#define SETPROPERTY_H

#include <ItemAction.h>

namespace hierhin {
namespace sys {


class SetProperty : public hierhin::ItemAction
{
public:
    SetProperty();

private:
    menu::def::ActionDef actionDef() const override;

private:
    QVariant actImpl(const QVariantList &args, Item *item) override;
};

} // namespace sys
} // namespace hierhin

#endif // SETPROPERTY_H

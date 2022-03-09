#ifndef SETPROPERTY_H
#define SETPROPERTY_H

#include <Method.h>

namespace hierhin {
namespace sys {


class SetProperty : public hierhin::Method
{
public:
    SetProperty();

private:
    menu::def::ActionDef actionDef() const override;

private:
    QVariant actImpl(const QVariantList &args, Item *item, const menu::TaskId &taskId) override;
};

} // namespace sys
} // namespace hierhin

#endif // SETPROPERTY_H

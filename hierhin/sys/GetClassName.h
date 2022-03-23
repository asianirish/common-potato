#ifndef HIERHIN_SYS_GETCLASSNAME_H
#define HIERHIN_SYS_GETCLASSNAME_H

#include <Method.h>

namespace hierhin {
namespace sys {

class GetClassName : public hierhin::Method
{
public:
    GetClassName();

private:
    menu::def::ActionDef actionDef() const override {
        return menu::def::ActionDef();
    }

private:
    QVariant actImpl(const QVariantList &args, Item *item) override;
};

} // namespace sys
} // namespace hierhin

#endif // HIERHIN_SYS_GETCLASSNAME_H

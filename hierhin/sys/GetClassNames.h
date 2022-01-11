#ifndef HIERHIN_SYS_GETCLASSNAMES_H
#define HIERHIN_SYS_GETCLASSNAMES_H

#include <Method.h>

namespace hierhin {
namespace sys {

class GetClassNames : public hierhin::Method
{
public:
    GetClassNames();

private:
    menu::def::ActionDef actionDef() const override {
        return menu::def::ActionDef();
    }

private:
    QVariant actImpl(const QVariantList &args, Item *item) override;
};

} // namespace sys
} // namespace hierhin

#endif // HIERHIN_SYS_GETCLASSNAMES_H

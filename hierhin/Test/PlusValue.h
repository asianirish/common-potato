#ifndef PLUSVALUE_H
#define PLUSVALUE_H

#include <ItemAction.h>

using namespace hierhin;

class PlusValue : public ItemAction
{
public:
    PlusValue();

private:
    QVariant actImpl(const QVariantList &args, Item *item) final;

    menu::def::ActionDef actionDef() const;
};

#endif // PLUSVALUE_H

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
};

#endif // PLUSVALUE_H

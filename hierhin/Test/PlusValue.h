#ifndef PLUSVALUE_H
#define PLUSVALUE_H

#include <Method.h>

using namespace hierhin;

class PlusValue : public Method
{
public:
    PlusValue();

private:
    QVariant actImpl(const QVariantList &args, Item *item, const menu::TaskId &taskId) final;

    menu::def::ActionDef actionDef() const;
};

#endif // PLUSVALUE_H

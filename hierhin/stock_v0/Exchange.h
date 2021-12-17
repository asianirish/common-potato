#ifndef STOCK_V0_EXCHANGE_H
#define STOCK_V0_EXCHANGE_H

#include <hierhin/Essence.h>

using namespace hierhin;

namespace stock_v0 {

class Exchange : public Essence
{
public:
    Exchange();

    NodeDef nodeDef() const override;

protected:
    void executeImpl(Item *item, const QString &command, const QVariantList &args) const override;
};

} // namespace stock_v0

#endif // STOCK_V0_EXCHANGE_H

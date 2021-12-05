#ifndef STOCK_V0_EXCHANGE_H
#define STOCK_V0_EXCHANGE_H

#include <hierhin/Essence.h>

using namespace hierhin;

namespace stock_v0 {

class Exchange : public Essence
{
public:
    Exchange();

    void execute(Item *item) override;

    NodeDef nodeDef() const override;
};

} // namespace stock_v0

#endif // STOCK_V0_EXCHANGE_H

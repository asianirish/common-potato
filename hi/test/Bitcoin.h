#ifndef TEST_BITCOIN_H
#define TEST_BITCOIN_H

#include "Currency.h"

namespace test {

class Bitcoin : public test::Currency
{
public:
    Bitcoin();

    QString code() const override;
};

} // namespace test

#endif // TEST_BITCOIN_H

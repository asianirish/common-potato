#ifndef TEST_BITCOIN_H
#define TEST_BITCOIN_H

#include "Currency.h"

namespace test {

class Bitcoin : public test::Currency
{
    Q_OBJECT
public:
    Bitcoin();

    QString code() const override;

private:
    QMap<QString, hi::FieldDef> fieldDefsSpecific() const override;
};

} // namespace test

#endif // TEST_BITCOIN_H

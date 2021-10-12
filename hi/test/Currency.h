#ifndef TEST_CURRENCY_H
#define TEST_CURRENCY_H

#include <Item.h>

namespace test {

class Currency : public hi::Item
{
    Q_OBJECT
public:
    explicit Currency(QObject *parent = nullptr);

    virtual QString code() const;

protected:
    QMap<QString, hi::FieldDef> fieldDefsSpecific() const override;

};

} // namespace test

#endif // TEST_CURRENCY_H

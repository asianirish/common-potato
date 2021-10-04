#ifndef TEST_CURRENCY_H
#define TEST_CURRENCY_H

#include <Item.h>

namespace test {

class Currency : public hi::Item
{
    Q_OBJECT
public:
    explicit Currency(QObject *parent = nullptr);

};

} // namespace test

#endif // TEST_CURRENCY_H

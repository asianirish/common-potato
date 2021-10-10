#ifndef TEST_USER_H
#define TEST_USER_H

#include <Item.h>

namespace test {

class User : public hi::Item
{
public:
    User(QObject *parent = nullptr);

private:
    QMap<QString, hi::FieldDef> fieldDefsSpecific() const override;
};

} // namespace test

#endif // TEST_USER_H

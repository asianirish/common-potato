#include "Bitcoin.h"

namespace test {

Bitcoin::Bitcoin()
{

}

QString Bitcoin::code() const
{
    return QString("BTC");
}

QMap<QString, hi::FieldDef> Bitcoin::fieldDefsSpecific() const
{
    QMap<QString, hi::FieldDef> myFieldDefs;
    QMap<QString, hi::FieldDef> parentFieldDefs = Currency::fieldDefsSpecific();

    //from QT 5.15
    myFieldDefs.insert(parentFieldDefs);

    hi::FieldDef specialBitcoinValueDef;
    myFieldDefs.insert("specialBitcoinValue", specialBitcoinValueDef);

    return myFieldDefs;
}

} // namespace test

#include "Currency.h"

namespace test {

Currency::Currency(QObject *parent) : hi::Item(parent)
{

}

QMap<QString, hi::FieldDef> Currency::fieldDefs() const
{
    hi::FieldDef codeDef;
    hi::FieldDef usdPriceDef;
    usdPriceDef.setDefaultValue(0);
    return {{"code", codeDef}, {"usdPrice", usdPriceDef}};
}

} // namespace test

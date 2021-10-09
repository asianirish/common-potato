#include "Currency.h"

#include <hi/val/NotEqualTo.h>

namespace test {

Currency::Currency(QObject *parent) : hi::Item(parent)
{

}

QMap<QString, hi::FieldDef> Currency::fieldDefsSpecific() const
{
    hi::FieldDef codeDef;
    hi::ValidatorPtr notUsd = hi::ValidatorPtr(new hi::val::NotEqualTo());
    notUsd.dynamicCast<hi::val::NotEqualTo>()->setValue(QString("USD"));
    codeDef.addValidator(notUsd);

    hi::FieldDef usdPriceDef;
    usdPriceDef.setDefaultValue(0);
    return {{"code", codeDef}, {"usdPrice", usdPriceDef}};
}

} // namespace test

#include "Currency.h"

#include <hi/val/NotEqualTo.h>

namespace test {

Currency::Currency(QObject *parent) : hi::Item(parent)
{

}

QString Currency::code() const
{
    return field("code").toString();
}

QMap<QString, hi::FieldDef> Currency::fieldDefsSpecific() const
{
    hi::FieldDef codeDef("test::Currency"); //TODO: does the presence of className mean that the field is not inheritable?
    hi::ValidatorPtr notUsd = hi::ValidatorPtr(new hi::val::NotEqualTo());
    notUsd.dynamicCast<hi::val::NotEqualTo>()->setValue(QString("USD"));
    codeDef.setIsInheritable(false);
    codeDef.addValidator(notUsd);

    hi::FieldDef usdPriceDef("test::Currency");
    usdPriceDef.setDefaultValue(0);
    return {{"code", codeDef}, {"usdPrice", usdPriceDef}};
}

} // namespace test

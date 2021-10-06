#include "Currency.h"

namespace test {

Currency::Currency(QObject *parent) : hi::Item(parent)
{

}

QMap<QString, hi::FieldDef> Currency::fieldDefs() const
{
    hi::FieldDef codeDef;
    return {{"code", codeDef}};
}

} // namespace test

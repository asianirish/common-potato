#include "List.h"

namespace hi {
namespace val {

List::List()
{

}

List::List(const QVariantList &values) : _values(values)
{

}

bool List::validate(const QVariant &value) const
{
    return _values.contains(value);
}

QString List::errorMessage() const
{
    QString msg("should be one of the specified values [");

    int i = 0;
    for (auto &val : _values) {
        if (i) {
            msg += ", ";
        }
        msg += val.toString();

        i++;
    }

    msg += "]";
    return msg;
}

QVariantList List::values() const
{
    return _values;
}

void List::setValues(const QVariantList &values)
{
    _values = values;
}

void List::addValue(const QVariant &value)
{
    _values.append(value);
}

} // namespace val
} // namespace hi

#include "Length.h"

namespace hi {
namespace val {

Length::Length()
{

}

bool Length::validate(const QVariant &value) const
{
    int length = value.toString().length();
    if (_minLength.isValid()) {
        bool ok = false;
        int minN = _minLength.toInt(&ok);

        if (ok) {
            if (length < minN) {
                return false;
            }
        }
    }

    if (_maxLength.isValid()) {
        bool ok = false;
        int maxN = _maxLength.toInt(&ok);

        if (ok) {
            if (length > maxN) {
                return false;
            }
        }
    }

    return true;
}

QVariant Length::minLength() const
{
    return _minLength;
}

void Length::setMinLength(const QVariant &minLength)
{
    _minLength = minLength;
}

QVariant Length::maxLength() const
{
    return _maxLength;
}

void Length::setMaxLength(const QVariant &maxLength)
{
    _maxLength = maxLength;
}

} // namespace val
} // namespace hi

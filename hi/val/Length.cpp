#include "Length.h"

namespace hi {
namespace val {

Length::Length()
{

}

Length::Length(int minLenght, int maxLength) : _minLength(minLenght),
    _maxLength(maxLength)
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

QString Length::errorMessage() const
{
    if (_minLength.isValid() && !_maxLength.isValid()) {
        return QString("the string must contain more than %1 characters").arg(_minLength.toString());
    }

    if (!_minLength.isValid() && _maxLength.isValid()) {
        return QString("the string must contain less than %1 characters").arg(_maxLength.toString());
    }

    if (_minLength.isValid() && _maxLength.isValid()) {
        return QString("the string must contain more than %1 and less then %2 characters").
                arg(_minLength.toString(),_maxLength.toString());
    }

    return QString("wrong length validator format");
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

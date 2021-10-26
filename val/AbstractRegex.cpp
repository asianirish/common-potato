#include "AbstractRegex.h"

#include <QRegularExpression>

namespace val {

AbstractRegex::AbstractRegex()
{

}

bool AbstractRegex::validate(const QVariant &value) const
{
    QRegularExpression re;
    re.setPattern(this->pattern());

    auto match = re.match(value.toString());

    return match.hasMatch();
}

QString AbstractRegex::errorMessage() const
{
    return QString("pattern doesn't match");
}

} // namespace val


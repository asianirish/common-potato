#include "Phone.h"

namespace val {

Phone::Phone()
{

}

QString Phone::errorMessage() const
{
    return QString("wrong phone number format");
}

QString Phone::pattern() const
{
    return QString("^(\\+\\d{1,3}( )?)?((\\(\\d{3}\\))|\\d{3})[- .]?\\d{3}[- .]?\\d{4}$");
}


} // namespace val


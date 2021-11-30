#include "Email.h"

namespace val {

Email::Email()
{

}

QString Email::errorMessage() const
{
    return QObject::tr("wrong email format");
}

QString Email::pattern() const
{
    return QString("[a-z0-9._%+-]+@[a-z0-9.-]+\\.[a-z]{2,}");
}

} // namespace val


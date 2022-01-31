#include "NotListType.h"

namespace hierhin {
namespace ex {

NotListType::NotListType() : NotListType(QString())
{

}

NotListType::NotListType(const QString &name) : PropertyException(name)
{

}

} // namespace ex
} // namespace hierhin

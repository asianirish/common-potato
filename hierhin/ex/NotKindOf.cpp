#include "NotKindOf.h"

namespace hierhin {
namespace ex {

NotKindOf::NotKindOf()
{

}

NotKindOf::NotKindOf(const QString &essenceClassName) : _essenceClassName(essenceClassName)
{

}

const QString &NotKindOf::essenceClassName() const
{
    return _essenceClassName;
}

void NotKindOf::setEssenceClassName(const QString &newEssenceClassName)
{
    _essenceClassName = newEssenceClassName;
}

} // namespace ex
} // namespace hierhin

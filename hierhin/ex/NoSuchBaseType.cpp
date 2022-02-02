#include "NoSuchBaseType.h"

namespace hierhin {
namespace ex {

NoSuchBaseType::NoSuchBaseType() : NoSuchBaseType(-1)
{

}

NoSuchBaseType::NoSuchBaseType(int wrongBaseType) : _wrongBaseType(wrongBaseType)
{

}

int NoSuchBaseType::wrongBaseType() const
{
    return _wrongBaseType;
}

void NoSuchBaseType::setWrongBaseType(int newWrongBaseType)
{
    _wrongBaseType = newWrongBaseType;
}

} // namespace ex
} // namespace hierhin

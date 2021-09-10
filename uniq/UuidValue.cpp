#include "UuidValue.h"

#include <QUuid>

namespace uniq {

UuidValue::UuidValue()
{

}

QString UuidValue::value() const
{
    return QUuid::createUuid().toString(QUuid::Id128);
}

} // namespace uniq

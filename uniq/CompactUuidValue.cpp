#include "CompactUuidValue.h"

#include <QUuid>

namespace uniq {

CompactUuidValue::CompactUuidValue()
{

}

QString CompactUuidValue::value() const
{
    bool ok = false;

    QString str = QUuid::createUuid().toString(QUuid::Id128);
    QString left = str.left(16);
    QString right = str.right(16);

    auto leftNum = left.toULongLong(&ok, 16);
    auto rightNum = right.toULongLong(&ok, 16);

    return QString::number(leftNum, 36) + QString::number(rightNum, 36);
}

} // namespace uniq

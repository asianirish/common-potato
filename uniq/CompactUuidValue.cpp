#include "CompactUuidValue.h"

#include <util/gfunc.h>

//#include <QDebug>
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

//    qDebug() << "leftNum:" << leftNum << "rightNum:" << rightNum;

    return util::int64_t2qstring_ext(leftNum) + util::int64_t2qstring_ext(rightNum);
}

} // namespace uniq

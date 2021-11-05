#include "gfunc.h"

namespace util
{

const char BASE_36[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char BASE_62[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

// maximum radix - base36
std::string uint64_t2string(uint64_t value, uint64_t radix) {
    std::string result;
    while (value > 0) {
        int64_t remainder = value % radix;
        value /= radix;
        result.insert(result.begin(), BASE_36[remainder]);
    }
    return result;
}

QString uint64_t2qstring(uint64_t value, uint64_t radix)
{
    QString result;
    while (value > 0) {
        int64_t remainder = value % radix;
        value /= radix;
        result.prepend(BASE_36[remainder]);
    }
    return result;
}

//max 36+26 = 62
QString uint64_t2qstring_ext(uint64_t value, uint64_t radix)
{
    QString result;
    while (value > 0) {
        int64_t remainder = value % radix;
        value /= radix;
        result.prepend(BASE_62[remainder]);
    }
    return result;
}

bool isNumber(const QVariant &arg)
{
    auto tp = arg.type();
    if (static_cast<int>(tp) == static_cast<int>(QMetaType::Int) ||
        static_cast<int>(tp) == static_cast<int>(QMetaType::UInt) ||
        static_cast<int>(tp) == static_cast<int>(QMetaType::LongLong) ||
        static_cast<int>(tp) == static_cast<int>(QMetaType::ULongLong) ||
        static_cast<int>(tp) == static_cast<int>(QMetaType::Double) ||
        static_cast<int>(tp) == static_cast<int>(QMetaType::Float) ||
        static_cast<int>(tp) == static_cast<int>(QMetaType::Short) ||
        static_cast<int>(tp) == static_cast<int>(QMetaType::UShort)) {

        return true;
    }

    return false;
}

bool isInteger(const QVariant &arg)
{
    auto tp = arg.type();
    if (static_cast<int>(tp) == static_cast<int>(QMetaType::Int) ||
        static_cast<int>(tp) == static_cast<int>(QMetaType::UInt) ||
        static_cast<int>(tp) == static_cast<int>(QMetaType::LongLong) ||
        static_cast<int>(tp) == static_cast<int>(QMetaType::ULongLong) ||
        static_cast<int>(tp) == static_cast<int>(QMetaType::Short) ||
        static_cast<int>(tp) == static_cast<int>(QMetaType::UShort)) {

        return true;
    }

    return false;
}

} // namespace util

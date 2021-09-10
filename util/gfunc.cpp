#include "gfunc.h"

namespace util
{

// maximum radix - base36
std::string int64_t2string(int64_t value, int64_t radix) {
    const char base36[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string result;
    while (value > 0) {
        int64_t remainder = value % radix;
        value /= radix;
        result.insert(result.begin(), base36[remainder]);
    }
    return result;
}

QString int64_t2qstring(int64_t value, int64_t radix)
{
    const char base36[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    QString result;
    while (value > 0) {
        int64_t remainder = value % radix;
        value /= radix;
        result.prepend(base36[remainder]);
    }
    return result;
}

} // namespace util

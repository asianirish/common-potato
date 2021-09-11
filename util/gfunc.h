#ifndef GFUNC_H
#define GFUNC_H

#include <string>
#include <cstdint>

#include <QString>

namespace util
{

// maximum radix - base36
std::string int64_t2string(int64_t value, int64_t radix);

QString int64_t2qstring(int64_t value, int64_t radix);

QString int64_t2qstring_ext(int64_t value, int64_t radix = 62);

} // namespace util

#endif // GFUNC_H

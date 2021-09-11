#ifndef GFUNC_H
#define GFUNC_H

#include <string>
#include <cstdint>

#include <QString>

namespace util
{

// maximum radix - base36
std::string int64_t2string(uint64_t value, uint64_t radix);

QString int64_t2qstring(uint64_t value, uint64_t radix);

QString int64_t2qstring_ext(uint64_t value, uint64_t radix = 62);

} // namespace util

#endif // GFUNC_H

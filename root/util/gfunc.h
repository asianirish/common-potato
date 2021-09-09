#ifndef GFUNC_H
#define GFUNC_H

#include <string>
#include <cstdint>

namespace util
{

// maximum radix - base36
std::string int64_t2string(int64_t value, int64_t radix);

} // namespace util

#endif // GFUNC_H

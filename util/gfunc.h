#ifndef GFUNC_H
#define GFUNC_H

#include <string>
#include <cstdint>

#include <QString>
#include <QVariant>

namespace potato_util
{

// maximum radix - base36
std::string uint64_t2string(uint64_t value, uint64_t radix);

QString uint64_t2qstring(uint64_t value, uint64_t radix);

QString uint64_t2qstring_ext(uint64_t value, uint64_t radix = 62);

bool isNumber(const QVariant &arg);

bool isInteger(const QVariant &arg);

int varToInt(const QVariant &arg);

double dRand(double dMin, double dMax);

} // namespace potato_util

#endif // GFUNC_H

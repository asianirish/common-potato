#include "TimeQStringValue.h"

#include <util/gfunc.h>

using namespace util;

namespace uniq {

TimeQStringValue::TimeQStringValue()
{

}

QString TimeQStringValue::value() const
{
    return uint64_t2qstring_ext(_tv.value());
}

} // namespace uniq

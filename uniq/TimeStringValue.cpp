#include "TimeStringValue.h"

#include <util/gfunc.h>

using namespace potato_util;

namespace uniq {

TimeStringValue::TimeStringValue()
{

}

string TimeStringValue::value() const
{
    return uint64_t2string(_tv.value(), 36);
}

} // namespace uniq

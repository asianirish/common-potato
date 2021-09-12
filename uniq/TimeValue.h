#ifndef UNIQ_TIMEVALUE_H
#define UNIQ_TIMEVALUE_H

#include <chrono>
#include <ctime>

#include "Value.h"

using namespace std;

namespace uniq {

class TimeValue : public Value<int64_t>
{
public:
    TimeValue();

    int64_t value() const override;

private:
    static int64_t _curValue;
    static int64_t _lastValue;

    void correctCurValue() const;
};

} // namespace uniq

#endif // UNIQ_TIMEVALUE_H

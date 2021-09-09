#include "TimeValue.h"

namespace uniq {

TimeValue::TimeValue() : _lastValue(0)
{

}

int64_t TimeValue::value() const
{
    auto p = std::chrono::system_clock::now();
    //TODO: milliseconds or microseconds or nanoseconds?
    _curValue = std::chrono::duration_cast<std::chrono::milliseconds>(
                       p.time_since_epoch()).count();

    if (_curValue <= _lastValue) {
        _curValue = _lastValue + 1;
        correctCurValue();
    }

     _lastValue = _curValue;

     return _curValue;
}

void TimeValue::correctCurValue() const
{
    if (_curValue <= _lastValue) {
        _curValue++;
        correctCurValue();
    }
}

} // namespace uniq

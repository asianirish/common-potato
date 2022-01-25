#include "TimeValue.h"

namespace uniq {

int64_t TimeValue::_curValue = 0;
int64_t TimeValue::_lastValue = 0;
TimeValue::DUR_TYPE TimeValue::_durType = TimeValue::MILLI;

TimeValue::TimeValue()
{

}

int64_t TimeValue::value() const
{
    auto p = std::chrono::system_clock::now();

    switch (_durType) {

    case MILLI:
        _curValue = std::chrono::duration_cast<std::chrono::milliseconds>(
                           p.time_since_epoch()).count();
        break;

    case MICRO:
        _curValue = std::chrono::duration_cast<std::chrono::microseconds>(
                           p.time_since_epoch()).count();
            break;

    case NANO:
        _curValue = std::chrono::duration_cast<std::chrono::nanoseconds>(
                           p.time_since_epoch()).count();
            break;
    }

    if (_curValue <= _lastValue) {
        _curValue = _lastValue + 1;
        correctCurValue();
    }

     _lastValue = _curValue;

     return _curValue;
}

TimeValue::DUR_TYPE TimeValue::durType()
{
    return _durType;
}

void TimeValue::setDurType(DUR_TYPE newDurType)
{
    _durType = newDurType;
}

void TimeValue::correctCurValue() const
{
    if (_curValue <= _lastValue) {
        _curValue++;
        correctCurValue();
    }
}

} // namespace uniq

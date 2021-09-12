#ifndef UNIQ_TIMEQSTRINGVALUE_H
#define UNIQ_TIMEQSTRINGVALUE_H

#include "TimeValue.h"

#include <QString>

namespace uniq {

class TimeQStringValue : public Value<QString>
{
public:
    TimeQStringValue();

    QString value() const override;

private:
    TimeValue _tv;
};

} // namespace uniq

#endif // UNIQ_TIMEQSTRINGVALUE_H

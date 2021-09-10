#ifndef UNIQ_TIMESTRINGVALUE_H
#define UNIQ_TIMESTRINGVALUE_H

#include "TimeValue.h"

#include <string>

using namespace std;


namespace uniq {

class TimeStringValue : public Value<string>
{
public:
    TimeStringValue();

    string value() const override;

private:
    TimeValue _tv;
};

} // namespace uniq

#endif // UNIQ_TIMESTRINGVALUE_H

#ifndef UNIQ_TIMESTRINGVALUE_H
#define UNIQ_TIMESTRINGVALUE_H

#include "TimeValue.h"

#include <string>

using namespace std;


namespace uniq {

class UNIQLIB_EXPORT TimeStringValue : public Value<string>
{
public:
    TimeStringValue();

    string value() const override;

    bool isGlobal() const override {
        return false;
    }

private:
    TimeValue _tv;
};

} // namespace uniq

#endif // UNIQ_TIMESTRINGVALUE_H

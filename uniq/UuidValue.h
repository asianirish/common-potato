#ifndef UUIDVALUE_H
#define UUIDVALUE_H

#include "Value.h"

#include <QString>

namespace uniq {

class UNIQLIB_EXPORT UuidValue : public Value<QString>
{
public:
    UuidValue();

    QString value() const override;

    bool isGlobal() const override {
        return true;
    }

};

} // namespace uniq


#endif // UUIDVALUE_H

#ifndef UUIDVALUE_H
#define UUIDVALUE_H

#include <QString>

#include "Value.h"

namespace uniq {

class UuidValue : public Value<QString>
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

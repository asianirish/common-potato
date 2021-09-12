#ifndef UNIQ_COMPACTUUIDVALUE_H
#define UNIQ_COMPACTUUIDVALUE_H

#include <QString>

#include "Value.h"

namespace uniq {

class CompactUuidValue : public Value<QString>
{
public:
    CompactUuidValue();

    QString value() const override;

    bool isGlobal() const override {
        return true;
    }

};

} // namespace uniq

#endif // UNIQ_COMPACTUUIDVALUE_H

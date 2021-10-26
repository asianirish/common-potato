#ifndef VAL_PHONE_H
#define VAL_PHONE_H

#include "AbstractRegex.h"

namespace val {

class Phone : public AbstractRegex
{
public:
    Phone();

    QString errorMessage() const override;

private:
    QString pattern() const override;
};

} // namespace val

#endif // VAL_PHONE_H

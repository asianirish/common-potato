#ifndef VAL_EMAIL_H
#define VAL_EMAIL_H

#include "AbstractRegex.h"

namespace val {

class Email : public AbstractRegex
{
public:
    Email();

    QString errorMessage() const override;

private:
    QString pattern() const override;
};

} // namespace val

#endif // VAL_EMAIL_H

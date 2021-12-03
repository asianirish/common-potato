#ifndef VAL_EMAIL_H
#define VAL_EMAIL_H

#include "AbstractRegex.h"

namespace val {

class Email : public AbstractRegex
{
    Q_DECLARE_TR_FUNCTIONS(val)
public:
    Email();

    QString errorMessage() const override;

private:
    QString pattern() const override;
};

} // namespace val

#endif // VAL_EMAIL_H

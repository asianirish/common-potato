#ifndef HI_VAL_EMAIL_H
#define HI_VAL_EMAIL_H

#include "AbstractRegex.h"

namespace hi {
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
} // namespace hi

#endif // HI_VAL_EMAIL_H

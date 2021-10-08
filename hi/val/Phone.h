#ifndef HI_VAL_PHONE_H
#define HI_VAL_PHONE_H

#include "AbstractRegex.h"

namespace hi {
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
} // namespace hi

#endif // HI_VAL_PHONE_H

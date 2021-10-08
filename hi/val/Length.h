#ifndef HI_VAL_LENGTH_H
#define HI_VAL_LENGTH_H

#include "Validator.h"

namespace hi {
namespace val {

class Length : public Validator
{
public:
    Length();

    bool validate(const QVariant &value) const override;
    QString errorMessage() const override;

    QVariant minLength() const;
    void setMinLength(const QVariant &minLength);

    QVariant maxLength() const;
    void setMaxLength(const QVariant &maxLength);

private:
    QVariant _minLength;
    QVariant _maxLength;
};

} // namespace val
} // namespace hi

#endif // HI_VAL_LENGTH_H

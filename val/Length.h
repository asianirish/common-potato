#ifndef VAL_LENGTH_H
#define VAL_LENGTH_H

#include "Validator.h"

namespace val {

class Length : public Validator
{
    Q_DECLARE_TR_FUNCTIONS(val)
public:
    Length();

    Length(int minLenght, int maxLength);

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

#endif // VAL_LENGTH_H

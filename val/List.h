#ifndef VAL_LIST_H
#define VAL_LIST_H

#include "Validator.h"

namespace val {

class List : public Validator
{
    Q_DECLARE_TR_FUNCTIONS(val)
public:
    List();

    List(const QVariantList &values);

    bool validate(const QVariant &value) const override;
    QString errorMessage() const override;

    QVariantList values() const;
    void setValues(const QVariantList &values);
    void addValue(const QVariant &value);

private:
    QVariantList _values;
};

} // namespace val

#endif // VAL_LIST_H

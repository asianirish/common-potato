#ifndef HI_VAL_LIST_H
#define HI_VAL_LIST_H

#include "Validator.h"

namespace hi {
namespace val {

class List : public Validator
{
public:
    List();

    bool validate(const QVariant &value) const override;
    QString errorMessage() const override;

    QVariantList values() const;
    void setValues(const QVariantList &values);
    void addValue(const QVariant &value);

private:
    QVariantList _values;
};

} // namespace val
} // namespace hi

#endif // HI_VAL_LIST_H

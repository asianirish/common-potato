#ifndef FIELDDEF_H
#define FIELDDEF_H

#include <QVariant>

namespace hi {

class FieldDef
{
public:
    FieldDef();

    QVariant defaultValue() const;
    void setDefaultValue(const QVariant &defaultValue);

private:
    QVariant _defaultValue;
    //TODO: QMetaType _metaType;?
    //TODO: constraints
};

} // namespace hi

#endif // FIELDDEF_H

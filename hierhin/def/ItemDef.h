#ifndef HIERHIN_DEF_ITEMDEF_H
#define HIERHIN_DEF_ITEMDEF_H

#include "PropertyDef.h"

#include <QString>
#include <QMap>

namespace hierhin {
namespace def {

typedef QList<PropertyDef> PropertyDefList;

typedef QMap<QString, PropertyDefList> PropertyDefs;

class ItemDef
{
public:
    ItemDef();

    bool isLimitedPropertyList() const;
    void setIsLimitedPropertyList(bool isLimitedPropertyList);

    PropertyDefs propertyDefs() const;
    void setPropertyDefs(const PropertyDefs &propertyDefs);
    void insertPropertyDef(const QString &name, const PropertyDefList &propertyDef);

    //'false' means 'no limitations'
    operator bool() const;

private:
    bool _isLimitedPropertyList; // limited to the specified set of definitions
    PropertyDefs _propertyDefs; //TODO: several property definition per every property!

    virtual bool toBool() const;
};

} // namespace def
} // namespace hierhin

#endif // HIERHIN_DEF_ITEMDEF_H

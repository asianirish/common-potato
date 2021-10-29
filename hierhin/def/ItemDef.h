#ifndef HIERHIN_DEF_ITEMDEF_H
#define HIERHIN_DEF_ITEMDEF_H

#include "PropertyDef.h"

#include <QString>
#include <QMap>

namespace hierhin {
namespace def {

class ItemDef
{
public:
    ItemDef();

    QString essenceClass() const;
    void setEssenceClass(const QString &essenceClass);

    bool isLimitedPropertyList() const;
    void setIsLimitedPropertyList(bool isLimitedPropertyList);

    QMap<QString, PropertyDef> propertyDefs() const;
    void setPropertyDefs(const QMap<QString, PropertyDef> &propertyDefs);
    void insertPropertyDef(const QString &name, const PropertyDef &propertyDef);

private:
    QString _essenceClass;
    bool _isLimitedPropertyList; // limited to the specified set of definitions
    QMap<QString, PropertyDef> _propertyDefs;
};

} // namespace def
} // namespace hierhin

#endif // HIERHIN_DEF_ITEMDEF_H

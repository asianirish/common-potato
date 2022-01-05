#ifndef HIERHIN_DEF_ITEMDEF_H
#define HIERHIN_DEF_ITEMDEF_H

#include "PropertyDef.h"
#include "CommandDef.h"

#include <QString>
#include <QMap>

namespace hierhin {
namespace def {

class ItemDef
{
public:
    ItemDef();

    bool isLimitedPropertyList() const;
    void setIsLimitedPropertyList(bool isLimitedPropertyList);

    QMap<QString, PropertyDef> propertyDefs() const;
    void setPropertyDefs(const QMap<QString, PropertyDef> &propertyDefs);
    void insertPropertyDef(const PropertyDef &propertyDef);

    //'false' means 'no limitations'
    operator bool() const;

    void validateProperty(const QString &name, const QVariant &value);

    const QMap<QString, CommandDef> &commandDefs() const;
    void setCommandDefs(const QMap<QString, CommandDef> &newCommandDefs);
    void insertCommandDef(const CommandDef &commandDef);

private:
    bool _isLimitedPropertyList; // limited to the specified set of definitions
    QMap<QString, PropertyDef> _propertyDefs;
    QMap<QString, CommandDef> _commandDefs;

    virtual bool toBool() const;
};

} // namespace def
} // namespace hierhin

#endif // HIERHIN_DEF_ITEMDEF_H

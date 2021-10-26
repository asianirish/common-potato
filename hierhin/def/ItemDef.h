#ifndef HIERHIN_DEF_ITEMDEF_H
#define HIERHIN_DEF_ITEMDEF_H

#include <QString>

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

private:
    QString _essenceClass;
    //TODO: propertyDefs
    bool _isLimitedPropertyList; // limited to the specified set of definitions
};

} // namespace def
} // namespace hierhin

#endif // HIERHIN_DEF_ITEMDEF_H

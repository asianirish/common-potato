#ifndef HIERHIN_DEF_ITEMREQ_H
#define HIERHIN_DEF_ITEMREQ_H

#include "../type.h"

#include <QStringList>
#include <QSharedPointer>

namespace hierhin {
namespace def {


class ItemReq
{
public:
    static const QString BASE_ESSENCE_CLASS;

    ItemReq();

    ItemReq(const QString &className, bool canBeEssenceless = true);

    const QStringList &classNames() const;
    void setClassNames(const QStringList &newClassNames);
    void addClassName(const QString &newClassName);

    bool canBeEssenceless() const;
    void setCanBeEssenceless(bool newCanBeEssenceless);

    void validate(ItemPtr item, const Role &role) const;

    bool alwaysValid() const;
    void setAlwaysValid(bool alwaysValid);

    bool isMandatory() const;
    void setIsMandatory(bool isMandatory);

private:
    QStringList _classNames;
    bool _canBeEssenceless;
    bool _alwaysValid;
    bool _isMandatory;
};

} // namespace def
} // namespace hierhin

#endif // HIERHIN_DEF_ITEMREQ_H

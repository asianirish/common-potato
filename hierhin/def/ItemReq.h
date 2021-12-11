#ifndef HIERHIN_DEF_ITEMREQ_H
#define HIERHIN_DEF_ITEMREQ_H

#include <QStringList>
#include <QSharedPointer>

namespace hierhin {

class Item;
typedef QSharedPointer<Item> ItemPtr;

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

    void validate(ItemPtr item) const;

private:
    QStringList _classNames;
    bool _canBeEssenceless;
};

} // namespace def
} // namespace hierhin

#endif // HIERHIN_DEF_ITEMREQ_H

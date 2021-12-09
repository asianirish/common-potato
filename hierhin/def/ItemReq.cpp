#include "ItemReq.h"
#include "Item.h"

namespace hierhin {
namespace def {

const QString ItemReq::BASE_ITEM_CLASS("hierhin::Item");

ItemReq::ItemReq() : ItemReq(BASE_ITEM_CLASS)
{

}

ItemReq::ItemReq(const QString &className) : _canBeEssenceless(false)
{
    addClassName(className);
}

const QStringList &ItemReq::classNames() const
{
    return _classNames;
}

void ItemReq::setClassNames(const QStringList &newClassNames)
{
    _classNames = newClassNames;
}

void ItemReq::addClassName(const QString &newClassName)
{
    _classNames.append(newClassName);
}

bool ItemReq::canBeEssenceless() const
{
    return _canBeEssenceless;
}

void ItemReq::setCanBeEssenceless(bool newCanBeEssenceless)
{
    _canBeEssenceless = newCanBeEssenceless;
}

void ItemReq::validate(ItemPtr item) const
{
//TODO: implement
    Q_UNUSED(item)
}

} // namespace def
} // namespace hierhin

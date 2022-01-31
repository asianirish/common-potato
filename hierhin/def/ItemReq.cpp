#include "ItemReq.h"
#include "Item.h"

#include "ex/CanNotBeEssenceless.h"
#include "ex/IncompatibleEssenceClass.h"

namespace hierhin {
namespace def {

const QString ItemReq::BASE_ESSENCE_CLASS(ESSENCE_CLASS(hierhin::Essence));

ItemReq::ItemReq() : ItemReq(BASE_ESSENCE_CLASS)
{

}

ItemReq::ItemReq(const QString &className, bool canBeEssenceless) : _canBeEssenceless(canBeEssenceless),
    _alwaysValid(false),
    _isMandatory(false)
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

void ItemReq::validate(ItemPtr item, const Role &role) const
{
    if (_alwaysValid) {
        return;
    }

    if (item->essenceClassName().isEmpty()) {
        if (!_canBeEssenceless) {
            throw ex::CanNotBeEssenceless(role);
        }

        return;
    }

    for (auto &clName : _classNames) {
        if (item->isKindOf(clName)) {
            return;
        }
    }

    throw ex::IncompatibleEssenceClass(role);
}

bool ItemReq::alwaysValid() const
{
    return _alwaysValid;
}

void ItemReq::setAlwaysValid(bool alwaysValid)
{
    _alwaysValid = alwaysValid;
}

bool ItemReq::isMandatory() const
{
    return _isMandatory;
}

void ItemReq::setIsMandatory(bool isMandatory)
{
    _isMandatory = isMandatory;
}

} // namespace def
} // namespace hierhin

#include "ItemRef.h"

namespace hierhin {
namespace nav {

ItemRef stringToItemRef(const QString str) {
    return hierhin::nav::ItemRef(str);
}

ItemRef::ItemRef() : ItemRef(QString())
{

}

ItemRef::ItemRef(const QString &pathStr) : _path(pathStr)
{

}

ItemRef::ItemRef(const Path &path) : _path(path)
{

}

const Path &ItemRef::path() const
{
    return _path;
}

void ItemRef::setPath(const Path &newPath)
{
    _path = newPath;
}

ItemPtr ItemRef::ptr(ItemPtr source)
{
    ConstItemPtr constItem = source.staticCast<const Item>();
    return ptr(constItem).constCast<Item>();
}

ConstItemPtr ItemRef::ptr(ConstItemPtr source) const
{
    if (!source) {
        return {};
    }

    return _path.go(source);
}

QString ItemRef::toString() const
{
    return _path.toString();
}

void ItemRef::fromString(const QString &pathStr)
{
    return _path.fromString(pathStr);
}

ItemRef::operator QString() const
{
    return toString();
}

int ItemRef::typeId()
{
    return QMetaType::type("hierhin::nav::ItemRef");
}

} // namespace nav
} // namespace hierhin

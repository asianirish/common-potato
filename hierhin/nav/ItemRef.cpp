#include "ItemRef.h"
#include "Item.h"

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

ItemRef::ItemRef(const ItemPtr &ptr) : _ptr(ptr)
{

}

const Path &ItemRef::path() const
{
    if (_ptr) {
        if (_ptr->absPath() != _path) {
            _path = _ptr->absPath();
        }
    }

    return _path;
}

void ItemRef::setPath(const Path &newPath)
{
    _path = newPath;
    _ptr.clear();
}

ItemPtr ItemRef::ptr(ItemPtr source)
{
    ConstItemPtr constItem = source.staticCast<const Item>();
    return ptr(constItem).constCast<Item>();
}

ConstItemPtr ItemRef::ptr(ConstItemPtr source) const
{
    if (_ptr) {
        return _ptr;
    }

    if (!source) {
        return {};
    }

    return _path.go(source);
}

QString ItemRef::toString() const
{
    return path().toString();
}

void ItemRef::fromString(const QString &pathStr)
{
    auto pth = path();
    return pth.fromString(pathStr);
}

ItemRef::operator QString() const
{
    return toString();
}

int ItemRef::typeId()
{
    //TODO: or use qMetaTypeId<hierhin::nav::ItemRef>())
    return QMetaType::type("hierhin::nav::ItemRef");
}

void ItemRef::setPtr(ItemPtr newPtr)
{
    _ptr = newPtr;
}

} // namespace nav
} // namespace hierhin

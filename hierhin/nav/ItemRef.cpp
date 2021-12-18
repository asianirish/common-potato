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

ItemPtr ItemRef::ptr(ItemPtr source) const
{
    if (!source) {
        return {};
    }

    if (_ptr) {
        return _ptr;
    }

    _ptr = _path.go(source);
    return _ptr;
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

} // namespace nav
} // namespace hierhin

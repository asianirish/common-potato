#include "ItemRef.h"

namespace hierhin {
namespace nav {

ItemRef::ItemRef() : ItemRef(QString())
{

}

ItemRef::ItemRef(const QString &pathStr) : _path(pathStr)
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

ItemPtr ItemRef::source() const
{
    return _source;
}

void ItemRef::setSource(ItemPtr newSource)
{
    _source = newSource;
}

ItemPtr ItemRef::ptr() const
{
    if (_source) {
        return {};
    }

    if (_ptr) {
        return _ptr;
    }

    _ptr = _path.go(_source);
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

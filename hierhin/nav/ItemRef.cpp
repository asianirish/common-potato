#include "ItemRef.h"

namespace hierhin {
namespace nav {

ItemRef::ItemRef()
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

} // namespace nav
} // namespace hierhin

#ifndef HIERHIN_NAV_ITEMREF_H
#define HIERHIN_NAV_ITEMREF_H

#include "nav/Path.h"

#include <type.h>

namespace hierhin {
namespace nav {

class ItemRef
{
public:
    ItemRef();
    ItemRef(const QString &pathStr);
    ItemRef(const Path &path);

    const Path &path() const;
    void setPath(const Path &newPath);

    ItemPtr ptr(ItemPtr source);
    ConstItemPtr ptr() const;

    QString toString() const;
    void fromString(const QString &pathStr);

    operator QString() const;

private:
    Path _path;

    [[deprecated]]
    mutable ItemPtr _ptr;
};

//from converters:
ItemRef stringToItemRef(const QString str);

} // namespace nav
} // namespace hierhin

Q_DECLARE_METATYPE(hierhin::nav::ItemRef)

class TestType
{};

Q_DECLARE_METATYPE(TestType)

#endif // HIERHIN_NAV_ITEMREF_H

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

    const Path &path() const;
    void setPath(const Path &newPath);


    ItemPtr source() const;
    void setSource(ItemPtr newSource);

    ItemPtr ptr() const;

    QString toString() const;

    operator QString() const;

private:
    Path _path;
    ItemPtr _source;
    mutable ItemPtr _ptr;
};

} // namespace nav
} // namespace hierhin

Q_DECLARE_METATYPE(hierhin::nav::ItemRef)

class TestType
{};

Q_DECLARE_METATYPE(TestType)

#endif // HIERHIN_NAV_ITEMREF_H

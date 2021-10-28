#ifndef SINGLETONREGISTRY_H
#define SINGLETONREGISTRY_H

#include "LazyPointer.h"

#include <QString>
#include <QMap>

namespace util {

template <typename Base>
class SingletonRegistry
{
    static QSharedPointer<Base> ptr(const QString className);
private:
    static QMap<QString, LazyPointer<Base> > _objects;
};

template<typename Base>
QSharedPointer<Base> SingletonRegistry<Base>::ptr(const QString className)
{
    if (!_objects.contains(className)) {
        LazyPointer<Base> lptr(className);
        _objects.insert(className, lptr);
    }

    return _objects.value(className).ptr();
}

}

#endif // SINGLETONREGISTRY_H
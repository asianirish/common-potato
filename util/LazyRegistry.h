#ifndef LAZYREGISTRY_H
#define LAZYREGISTRY_H

#include <QMap>
#include <QSharedPointer>

namespace potato_util {

template <typename K, typename T>
class LazyRegistry
{
public:
    static QSharedPointer<T> ptr(const K &k);
    static T &obj(const K &k);

    static void destruct() {
        _objects.clear();
    }

private:
    static QMap<K, QSharedPointer<T> > _objects;
};

template<typename K, typename T>
QMap<K, QSharedPointer<T> > LazyRegistry<K,T>::_objects;

template<typename K, typename T>
QSharedPointer<T> LazyRegistry<K,T>::ptr(const K &k)
{
    if (!_objects.contains(k)) {
        QSharedPointer<T> lptr(new T());
        _objects.insert(k, lptr);
    }

    return _objects.value(k);
}

template<typename K, typename T>
T &LazyRegistry<K,T>::obj(const K &k)
{
    return *ptr(k);
}

} // namespace potato_util

#endif // LAZYREGISTRY_H

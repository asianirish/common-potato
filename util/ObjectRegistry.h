#ifndef OBJECTREGISTRY_H
#define OBJECTREGISTRY_H


#include <QMap>
#include <QSharedPointer>

namespace potato_util {

template <typename K, typename BaseClass>
class ObjectRegistry
{
public:

    static void registerObject(const K &k, QSharedPointer<BaseClass> ptr);

    template <typename ChildClass>
    static void createObject(const K &k) {
        QSharedPointer<BaseClass> ptr = QSharedPointer<BaseClass>(new ChildClass());
        registerObject(k, ptr);
    }

    static QSharedPointer<BaseClass> ptr(const K &k);

    static void destruct() {
        _objects.clear();
    }

private:
    static QMap<K, QSharedPointer<BaseClass> > _objects;
};

template<typename K, typename BaseClass>
QMap<K, QSharedPointer<BaseClass> > ObjectRegistry<K,BaseClass>::_objects;

template <typename K, typename BaseClass>
void ObjectRegistry<K, BaseClass>::registerObject(const K &k, QSharedPointer<BaseClass> ptr) {
    _objects.insert(k, ptr);
}

template<typename K, typename BaseClass>
QSharedPointer<BaseClass> ObjectRegistry<K,BaseClass>::ptr(const K &k)
{
    return _objects.value(k);
}

} // namespace potato_util


#endif // OBJECTREGISTRY_H

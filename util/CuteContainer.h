#ifndef ORDEREDNAMEDCONTAINER_H
#define ORDEREDNAMEDCONTAINER_H

#include "BaseWrapper.h"

#include <QString>
#include <QHash>
#include <QVector>
#include <QList>
#include <QVariant>
#include <QDebug>

namespace potato_util {

template<typename K, typename T, typename Wrapper>
class CuteContainer;

template<typename K, typename T>
class ObjectWrapper;

template<typename K, typename T, typename Wrapper = ObjectWrapper<K,T>>
class CuteIterator
{
public:
    CuteIterator(const CuteContainer<K,T,Wrapper> &c, int index) : _container(c),
        _index(index) {}

    //default constructor builds an invalid iterator
    CuteIterator() : _index(-1) {}

    bool operator !=(const CuteIterator<K,T,Wrapper> &other) {
        return (_index != other._index);
    }

    const CuteIterator<K,T,Wrapper> &operator++() {
        if ((_index + 1) < _container._keys.size()) {
            _index++;
        } else {
            _index = -1;
        }

        return *this;
    }

    T operator*() const {
        return _container.at(_index);
    }

    int index() const {
        return _index;
    }

    QString key() const {
        return _container.key(_index);
    }

private:
    CuteContainer<K,T,Wrapper> _container;
    int _index;
};

template<typename K, typename T>
class ObjectWrapper : public BaseWrapper
{
public:

    ObjectWrapper() {}

    T& value() {
        return _value;
    }

    void setValue(const T &object) {
        _value = object;
    }

    K key() const {
        return _key;
    }

    void setKey(const K &key) {
        _key = key;
    }

    QString name() const {
        return _name;
    }

    void setName(const QString &name) {
        _name = name;
    }

private:
    T _value;
    K _key;
    QString _name;
};

template<typename K, typename T>
class PointerWrapper  : public BaseWrapper
{
public:
    PointerWrapper() : _pointer(nullptr) {}

    T *value() {
        return _pointer;
    }

    void setValue(T *object) {
        _pointer = object;
    }

    K key() const {
        return _pointer->id();
    }

    void setKey(const K &key) {
        _pointer->setId(key);
    }

    QString name() const {
        return _pointer->name();
    }

    void setName(const QString &name) {
        _pointer->setName(name);
    }

private:
    T *_pointer;
};

template<typename K, typename T>
class SharedPointerWrapper  : public BaseWrapper
{
public:
    SharedPointerWrapper() : _pointer(nullptr) {}

    QSharedPointer<T> value() {
        return _pointer;
    }

    void setValue(const QSharedPointer<T> &object) {
        _pointer = object;
    }

    K key() const {
        return _pointer->id();
    }

    void setKey(const K &key) {
        _pointer->setId(key);
    }

    QString name() const {
        return _pointer->name();
    }

    void setName(const QString &name) {
        _pointer->setName(name);
    }

private:
    QSharedPointer<T> _pointer;
};

//TODO: optimize
template<typename K, typename T, typename Wrapper = ObjectWrapper<K,T>>
class CuteContainer
{
friend class CuteIterator<K,T,Wrapper>;
public:

    CuteContainer<K,T,Wrapper>() {
        testWrapper();
    }

    CuteContainer<K,T,Wrapper>(const CuteContainer<K,T,Wrapper> &other) {
        copy(other);
        testWrapper();
    }

    CuteContainer<K,T,Wrapper>(const QList<T> &args) {
        for (auto arg : args) {
            append(arg);
        }
        testWrapper();
    }

    CuteContainer<K,T,Wrapper>(const QVector<T> &args) {
        for (auto arg : args) {
            append(arg);
        }
        testWrapper();
    }

    CuteContainer<K,T,Wrapper>(std::initializer_list<QPair<K,T>> args) {
        for (auto arg : args) {
            insert(arg.first, arg.second);
        }
        testWrapper();
    }

    virtual ~CuteContainer<K,T,Wrapper>();

    void testWrapper() {
        BaseWrapper *wrapper = new Wrapper();
        delete wrapper;
    }

    CuteContainer<K,T,Wrapper> &operator =(const CuteContainer<K,T,Wrapper> &other) {
        copy(other);
        return *this;
    }

    CuteContainer<K,T,Wrapper> &operator =(const QList<T> &lst) {
        for (auto value : lst) {
            append(value);
        }

        return *this;
    }

    void copy(const CuteContainer<K,T,Wrapper> &other);

    typedef CuteIterator<K,T,Wrapper> iterator;

    iterator begin() const {
        if (_keys.isEmpty())
            return end();
        return iterator(*this, 0);
    }

    iterator end() const {
        return iterator(*this, -1);
    }

    K append(const T &value, const QString &name = QString());

    iterator insert(const K &key, const T &value, const QString &name = QString());

    iterator insertByIndex(int index, const T &value, const QString &name = QString());

    void replace(int index, const T &value) {
        insertByIndex(index, value);
    }

    void rename(const K &key, const QString &name, const QString &oldName = QString());

    CuteContainer<K,T,Wrapper> &operator <<(const T &value) {
        append(value);
        return *this;
    }

    CuteContainer<K,T,Wrapper> &operator <<(const QPair<QString,T> &pair) {
        insert(pair.first, pair.second);
        return *this;
    }


    T at(int index) const;

    T at(int index);

    T first() const;

    T value(const K &key, const T &defaultValue = T()) const;

    T valueByName(const QString &name, const T &defaultValue = T()) const;

    K keyByName(const QString &name, const K &defaultKey = K()) const;

    QString nameByKey(const K &key) const;

    int size() const {
        return _keys.size();
    }

    bool isEmpty() const {
        return _keys.isEmpty();
    }

    QList<K> keys() const {
        return _keys;
    }

    bool contains(const K &key) const {
        return _keys.contains(key);
    }

    bool containsName(const QString &name) const {
        return _nameMap.contains(name);
    }

    K key(int index) const {
        return _keys.value(index);
    }

    int index(const K &key) const {
        auto wrapper = _keyMap.value(key, nullptr);

        if (!wrapper) {
            return -1; //TODO: constant
        }

        return wrapper->index();
    }

    T last(const T &defaultValue = T()) const {
        return value(_keys.last(), defaultValue);
    }

    bool remove(const K &key);

    bool removeAt(int index);

    bool removeFirst();

    iterator erase(iterator pos);

    T takeFirst();

    QList<T> toList() const;

    operator QList<T> () const {
        return toList();
    }

protected:
    virtual K indexToKeyType(int index, const T &value) {
        (void)value; //TODO: use the value in case if the key depends of the value
        QVariant varKey(index);
        return varKey.value<K>();
    }

    virtual void addNamedValue(Wrapper*) {
        //do nothing
    }

    void addNamedValueProtected(Wrapper* wrapper, const QString &name) {
        _nameMap.insert(name, wrapper);
    }

private:
    QHash<K, Wrapper*> _keyMap;
    QHash<QString, Wrapper*> _nameMap;
    QList<K> _keys;
};

template<typename K, typename T, typename Wrapper>
CuteContainer<K,T,Wrapper>::~CuteContainer<K,T,Wrapper>() {
        for (auto wrapper : _keyMap) {
            delete wrapper;
        }

    _keyMap.clear();
    _nameMap.clear();
    _keys.clear();
}

template<typename K, typename T, typename Wrapper>
void CuteContainer<K,T,Wrapper>::copy(const CuteContainer<K,T,Wrapper> &other) {
    _keys = other._keys;

    for (Wrapper *sourceWrapper : other._keyMap) {
        Wrapper *targetWrapper = new Wrapper(*sourceWrapper); //create a new copy of the sourceWrapper
        _keyMap.insert(sourceWrapper->key(), targetWrapper);
    }

    for (Wrapper *sourceWrapper : other._nameMap) {
        Wrapper *targetWrapper = new Wrapper(*sourceWrapper); //create a new copy of the sourceWrapper
        _nameMap.insert(sourceWrapper->name(), targetWrapper);
    }

}

template<typename K, typename T, typename Wrapper>
K CuteContainer<K, T, Wrapper>::append(const T &value, const QString &name) {
    int index = _keys.size();
    Wrapper *wrapper = new Wrapper();
    wrapper->setIndex(index);
    wrapper->setValue(value);

    K key = indexToKeyType(index, value);
    wrapper->setKey(key);
    if (!name.isEmpty()) {
        wrapper->setName(name);
    }

    _keys.append(key);
    _keyMap.insert(key, wrapper);

    if (!name.isEmpty()) {
        _nameMap.insert(name, wrapper);
    } else {
        addNamedValue(wrapper);
    }

    return key;
}

template<typename K, typename T, typename Wrapper>
typename CuteContainer<K,T,Wrapper>::iterator CuteContainer<K,T,Wrapper>::insert(const K &key, const T &value, const QString &name) {
    Wrapper *wrapper = nullptr;

    if (_keys.contains(key)) {
        wrapper = _keyMap.value(key);
        //auto val = wrapper->value();
        wrapper->setValue(value); //just change a wrapper's value

        if (!name.isEmpty()) {
            if (wrapper->name() != name) {
                wrapper->setName(name);
                 _nameMap.remove(wrapper->name());
                 _nameMap.insert(name, wrapper);
            }
        }
    } else {
        _keys.append(key);
        wrapper = new Wrapper();
        wrapper->setIndex(_keys.size() - 1);
        wrapper->setValue(value);
        wrapper->setKey(key);
        _keyMap.insert(key, wrapper);
        if (!name.isEmpty()) {
            wrapper->setName(name);
            _nameMap.insert(name, wrapper);
        }
    }

    int index = wrapper->index();
    return iterator(*this, index);
}

template<typename K, typename T, typename Wrapper>
typename CuteContainer<K,T,Wrapper>::iterator CuteContainer<K,T,Wrapper>::insertByIndex(int index, const T &value, const QString &name) {
    K key = _keys.at(index);
    return insert(key, value, name);
}

template<typename K, typename T, typename Wrapper>
void CuteContainer<K,T,Wrapper>::rename(const K &key, const QString &name, const QString &oldName)
{
    Wrapper *wrapper = nullptr;
    if (_keys.contains(key)) {
        wrapper = _keyMap.value(key);

        QString oname = oldName;

        if (oldName.isEmpty()) {
            oname = wrapper->name();
        }

        if (!name.isEmpty()) {
            if (oname != name) {
                wrapper->setName(name);
                 _nameMap.remove(oname);
                 _nameMap.insert(name, wrapper);
            }
        }
    }
}

template<typename K, typename T, typename Wrapper>
T CuteContainer<K,T,Wrapper>::at(int index) const {
    K key = _keys.at(index);
    Wrapper *wrapper = _keyMap.value(key);
    return wrapper->value();
}

template<typename K, typename T, typename Wrapper>
T CuteContainer<K,T,Wrapper>::at(int index)
{
    K key = _keys.at(index);
    Wrapper *wrapper = _keyMap.value(key);
    return wrapper->value();
}

template<typename K, typename T, typename Wrapper>
T CuteContainer<K,T,Wrapper>::first() const {
    K key = _keys.first();
    Wrapper *wrapper = _keyMap.value(key);
    return wrapper->value();
}

template<typename K, typename T, typename Wrapper>
T CuteContainer<K,T,Wrapper>::value(const K &key, const T &defaultValue) const {
    Wrapper *wrapper = _keyMap.value(key, nullptr); //default is Wrapper*, not a T value

    if (!wrapper)
        return defaultValue;

    return wrapper->value();
}

template<typename K, typename T, typename Wrapper>
T CuteContainer<K,T,Wrapper>::valueByName(const QString &name, const T &defaultValue) const {
    Wrapper *wrapper = _nameMap.value(name, nullptr); //default is Wrapper*, not a T value

    if (!wrapper)
        return defaultValue;

    return wrapper->value();
}

template<typename K, typename T, typename Wrapper>
K CuteContainer<K,T,Wrapper>::keyByName(const QString &name, const K &defaultKey) const {
    Wrapper *wrapper = _nameMap.value(name, nullptr);

    if (!wrapper)
        return defaultKey;

    return wrapper->key();
}

template<typename K, typename T, typename Wrapper>
QString CuteContainer<K, T, Wrapper>::nameByKey(const K &key) const
{
    Wrapper *wrapper = _keyMap.value(key);

    if (!wrapper) {
        return QString(); //TODO: or exception?
    }

    return wrapper->name();
}


template<typename K, typename T, typename Wrapper>
bool CuteContainer<K,T,Wrapper>::remove(const K &key) {
    if (!_keyMap.contains(key))
        return false;

    Wrapper *wrapper = _keyMap.value(key);

    _keys.removeOne(key); //TODO: or suppor ObjectWrapper::_index and use keys.remove(wrapper->index()); (?)
    _nameMap.remove(wrapper->name());
    _keyMap.remove(key);

    delete wrapper;
    return true;
}

template<typename K, typename T, typename Wrapper>
bool CuteContainer<K,T,Wrapper>::removeAt(int index)
{
    K key = _keys.at(index);
    return remove(key);
}

template<typename K, typename T, typename Wrapper>
bool CuteContainer<K,T,Wrapper>::removeFirst()
{
    return removeAt(0);
}

template<typename K, typename T, typename Wrapper>
typename CuteContainer<K,T,Wrapper>::iterator CuteContainer<K,T,Wrapper>::erase(CuteContainer<K,T,Wrapper>::iterator pos)
{
    if (remove(pos.key())) {
        ++pos;
        return pos;
    }

    return iterator(*this, -1);
}

template<typename K, typename T, typename Wrapper>
T CuteContainer<K,T,Wrapper>::takeFirst()
{
    //The function assumes the container is not empty
    K key = _keys.first();
    Wrapper *wrapper = _keyMap.value(key);
    T value = wrapper->value();
    remove(key);

    return value;
}

template<typename K, typename T, typename Wrapper>
QList<T> CuteContainer<K,T,Wrapper>::toList() const
{
    QList<T> list;
    for (auto key : _keys) {
        list.append(_keyMap.value(key)->value());
    }

    return list;
}

} // namespace potato_util

#endif // ORDEREDNAMEDCONTAINER_H

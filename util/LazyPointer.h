#ifndef LAZYPOINTER_H
#define LAZYPOINTER_H

#include "Factory.h"

#include <QString>
#include <QSharedPointer>

namespace potato_util {

template <class Base>
class LazyPointer
{
public:

    LazyPointer() = default;

    LazyPointer(const QString &defaultClassName) : _className(defaultClassName) {}

    ~LazyPointer() {
        _ptr.clear();
    }

    QString className() const {
        return _className;
    }

    void setClassName(const QString &className) {
        _className = className;
    }

    QSharedPointer<Base> ptr() const {
        if (!_ptr) {
            _ptr = QSharedPointer<Base>(createPtr());
        }

        return _ptr;
    }

    QSharedPointer<Base> operator ->() {
        return ptr();
    }

    const QSharedPointer<Base> operator ->() const {
        return ptr();
    }

    operator bool() const {
        return _ptr;
    }

private:
    QString _className;
    mutable QSharedPointer<Base> _ptr;

    Base *createPtr() const {
        return Factory<Base>::create(_className.toStdString());
    }

};

} // namespace util





#endif // LAZYPOINTER_H

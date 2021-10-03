#ifndef LAZYPOINTER_H
#define LAZYPOINTER_H

#include "Factory.h"

#include <QString>
#include <QSharedPointer>

namespace util {

template <class Base>
class LazyPointer
{
public:

    LazyPointer(const QString &defaultClassName) : _className(defaultClassName) {}

//    ~LazyPointer() {

//    }

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

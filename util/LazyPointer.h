#ifndef LAZYPOINTER_H
#define LAZYPOINTER_H

#include "Factory.h"

#include <QString>

namespace util {

template <class Base>
class LazyPointer
{
public:

    LazyPointer(const QString &defaultClassName) : _className(defaultClassName),
        _ptr(nullptr) {}

    ~LazyPointer() {
        if (_ptr) {
            delete _ptr;
        }
    }

    QString className() const {
        return _className;
    }

    void setClassName(const QString &className) {
        _className = className;
    }

    Base *ptr() const {
        if (_ptr == nullptr) {
            _ptr = createPtr();
        }

        return _ptr;
    }

    //TODO: operator ->

private:
    QString _className;
    mutable Base *_ptr;

    Base *createPtr() const {
        return Factory<Base>::create(_className.toStdString());
    }

};

} // namespace util





#endif // LAZYPOINTER_H

#ifndef LAZYPOINTER_H
#define LAZYPOINTER_H

#include "Factory.h"

#include <QString>

namespace util {

template <class Base, const char *>
class LazyPointer
{
public:
    static const QString DEFAULT_CLASS_NAME;

    LazyPointer() : _className(DEFAULT_CLASS_NAME),
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

template <class Base, const char *defaultClassName>
const QString LazyPointer<Base, defaultClassName>::DEFAULT_CLASS_NAME(defaultClassName);

} // namespace util





#endif // LAZYPOINTER_H

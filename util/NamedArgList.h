#ifndef POTATO_UTIL_ARGONCONTAINER_H
#define POTATO_UTIL_ARGONCONTAINER_H

#include "CuteContainer.h"

namespace potato_util {

template<typename T, typename Wrapper = ObjectWrapper<QString,T>>
class NamedArgList : public CuteContainer<QString, T, Wrapper>
{
public:
    NamedArgList<T, Wrapper>() : CuteContainer<QString, T, Wrapper>() {}

    NamedArgList<T, Wrapper>(const QList<T> &args) : CuteContainer<QString, T, Wrapper>(args) {}

    NamedArgList<T, Wrapper>(const QVector<T> &args) : CuteContainer<QString, T, Wrapper>(args) {}

protected:

    virtual QString indexToKeyType(int index) {
        return QString("$") + QString::number(index);
    }
};

} // namespace potato_util

#endif // POTATO_UTIL_ARGONCONTAINER_H

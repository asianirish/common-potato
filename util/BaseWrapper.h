#ifndef POTATO_UTIL_BASEWRAPPER_H
#define POTATO_UTIL_BASEWRAPPER_H

namespace potato_util {

//a container element wrapper
class BaseWrapper
{
public:
    BaseWrapper();
    virtual ~BaseWrapper();

    int index() const;

    void setIndex(int index);

private:
    int _index;
};

} // namespace potato_util

#endif // POTATO_UTIL_BASEWRAPPER_H

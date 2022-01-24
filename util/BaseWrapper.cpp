#include "BaseWrapper.h"

namespace potato_util {

BaseWrapper::BaseWrapper() : _index(-1)
{

}

BaseWrapper::~BaseWrapper()
{

}

int BaseWrapper::index() const
{
    return _index;
}

void BaseWrapper::setIndex(int index)
{
    _index = index;
}

} // namespace potato_util

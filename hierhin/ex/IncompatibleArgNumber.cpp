#include "IncompatibleArgNumber.h"

namespace hierhin {
namespace ex {

IncompatibleArgNumber::IncompatibleArgNumber()
{

}

IncompatibleArgNumber::IncompatibleArgNumber(int actualArgNum, int definedArgNum) : _actualArgNum(actualArgNum),
    _definedArgNum(definedArgNum)
{

}

int IncompatibleArgNumber::actualArgNum() const
{
    return _actualArgNum;
}

void IncompatibleArgNumber::setActualArgNum(int newActualArgNum)
{
    _actualArgNum = newActualArgNum;
}

int IncompatibleArgNumber::definedArgNum() const
{
    return _definedArgNum;
}

void IncompatibleArgNumber::setDefinedArgNum(int newDefinedArgNum)
{
    _definedArgNum = newDefinedArgNum;
}

} // namespace ex
} // namespace hierhin

#ifndef HIERHIN_EX_INCOMPATIBLEARGNUMBER_H
#define HIERHIN_EX_INCOMPATIBLEARGNUMBER_H

#include "Exception.h"

namespace hierhin {
namespace ex {

class IncompatibleArgNumber : public Exception
{
    Q_DECLARE_TR_FUNCTIONS(ex)
public:
    IncompatibleArgNumber();
    IncompatibleArgNumber(int actualArgNum, int definedArgNum);

    int actualArgNum() const;
    void setActualArgNum(int newActualArgNum);

    int definedArgNum() const;
    void setDefinedArgNum(int newDefinedArgNum);

    QString cause() const override {
        return tr("Incompatible arg number") +
                "\n" + tr("Actual arg number:", "", _actualArgNum) +
                "\n" + tr("Defined arg number:", "", _definedArgNum);
    }

private:
    int _actualArgNum;
    int _definedArgNum;
};

} // namespace ex
} // namespace hierhin

#endif // HIERHIN_EX_INCOMPATIBLEARGNUMBER_H

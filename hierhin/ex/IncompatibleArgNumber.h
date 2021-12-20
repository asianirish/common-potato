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
                " " + tr("Actual arg number: %n", "", _actualArgNum) +
                " " + tr("Defined arg number: %n", "", _definedArgNum);
    }

private:
    int _actualArgNum;
    int _definedArgNum;
};

} // namespace ex
} // namespace hierhin

#endif // HIERHIN_EX_INCOMPATIBLEARGNUMBER_H

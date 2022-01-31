#ifndef INCOMPATIBLEESSENCEEXECUTION_H
#define INCOMPATIBLEESSENCEEXECUTION_H

#include "Exception.h"

namespace hierhin {
namespace ex {

class IncompatibleEssenceExecution : public hierhin::ex::Exception
{
    Q_DECLARE_TR_FUNCTIONS(ex)
public:
    IncompatibleEssenceExecution();
    IncompatibleEssenceExecution(const QString &intendedClass, const QString &actualClass);

    const QString &actualClass() const;
    void setActualClass(const QString &newActualClass);

    const QString &intendedClass() const;
    void setIntendedClass(const QString &newIntendedClass);

    QString cause() const override {
        return tr("incompatible essence execution Intended Class: %1, Actual Class: %2").arg(_intendedClass, _actualClass);
    }
private:
    QString _intendedClass;
    QString _actualClass;
};

} // namespace ex
} // namespace hierhin

#endif // INCOMPATIBLEESSENCEEXECUTION_H

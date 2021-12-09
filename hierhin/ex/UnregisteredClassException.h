#ifndef HIERHIN_EX_UNREGISTEREDCLASSEXCEPTION_H
#define HIERHIN_EX_UNREGISTEREDCLASSEXCEPTION_H

#include "Exception.h"

namespace hierhin {
namespace ex {

class UnregisteredClassException : public Exception
{
    Q_DECLARE_TR_FUNCTIONS(ex)
public:
    UnregisteredClassException();

    QString cause() const override {
        return tr("unregistered class name: ") + " '" + _className + "'";
    }

    const QString &className() const;
    void setClassName(const QString &newClassName);

private:
    QString _className;
};

} // namespace ex
} // namespace hierhin

#endif // HIERHIN_EX_UNREGISTEREDCLASSEXCEPTION_H

#ifndef HIERHIN_EXCHILDITEMEXCEPTION_H
#define HIERHIN_EXCHILDITEMEXCEPTION_H

#include "Exception.h"
#include "def/ItemReq.h"

namespace hierhin {
namespace ex {

class ChildItemException : public Exception
{
    Q_DECLARE_TR_FUNCTIONS(ex)
public:
    ChildItemException();
    ChildItemException(const Role &role);

    QString cause() const override {
        return tr("unknown child item exception");
    }

    const QString &role() const;
    void setRole(const QString &newRole);

private:
    QString _role;
};

} //namespace ex
} // namespace hierhin

#endif // HIERHIN_EXCHILDITEMEXCEPTION_H

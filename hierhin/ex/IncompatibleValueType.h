#ifndef HIERHIN_EX_INCOMPATIBLEVALUETYPE_H
#define HIERHIN_EX_INCOMPATIBLEVALUETYPE_H

#include "Exception.h"

namespace hierhin {
namespace ex {

class IncompatibleValueType : public Exception
{
    Q_DECLARE_TR_FUNCTIONS(ex)
public:
    IncompatibleValueType();
    IncompatibleValueType(int typeId);

    virtual QString cause() const {
        return tr("incompatible value type, required type id: %1").arg(_typeId);
    }
    int typeId() const;
    void setTypeId(int newTypeId);

private:
    int _typeId;
};

} // namespace ex
} // namespace hierhin

#endif // HIERHIN_EX_INCOMPATIBLEVALUETYPE_H

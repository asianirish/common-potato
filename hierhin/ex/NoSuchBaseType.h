#ifndef HIERHIN_EX_NOSUCHBASETYPE_H
#define HIERHIN_EX_NOSUCHBASETYPE_H

#include "Exception.h"

namespace hierhin {
namespace ex {

class NoSuchBaseType : public Exception
{
public:
    NoSuchBaseType();
    NoSuchBaseType(int wrongBaseType);

    QString cause() const override {
        return tr("no such base type %1").arg(_wrongBaseType);
    }

    int wrongBaseType() const;
    void setWrongBaseType(int newWrongBaseType);

private:
    int _wrongBaseType;
};

} // namespace ex
} // namespace hierhin

#endif // HIERHIN_EX_NOSUCHBASETYPE_H

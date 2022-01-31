#ifndef HIERHIN_EX_NOTKINDOF_H
#define HIERHIN_EX_NOTKINDOF_H

#include "Exception.h"

namespace hierhin {
namespace ex {

class NotKindOf : public Exception
{
public:
    NotKindOf();
    NotKindOf(const QString &essenceClassName);

    QString cause() const override {
        return tr("is not a kind of %1").arg(_essenceClassName);
    }

    const QString &essenceClassName() const;
    void setEssenceClassName(const QString &newEssenceClassName);

private:
    QString _essenceClassName;
};

} // namespace ex
} // namespace hierhin

#endif // HIERHIN_EX_NOTKINDOF_H

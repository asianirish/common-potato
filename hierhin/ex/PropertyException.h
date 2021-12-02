#ifndef HIERHINPROPERTYEXCEPTION_H
#define HIERHINPROPERTYEXCEPTION_H

#include "Exception.h"

namespace hierhin {
namespace ex {

class PropertyException : public Exception
{
public:
    PropertyException(const QString &name);

    QString cause() const override {
        return QObject::tr("unknown set property exception");
    }

    QString name() const;
    void setName(const QString &name);

private:
    QString _name;
};

} // namespace ex
} // namespace hierhin

#endif // HIERHINPROPERTYEXCEPTION_H

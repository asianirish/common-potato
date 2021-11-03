#ifndef HIERHINPROPERTYEXCEPTION_H
#define HIERHINPROPERTYEXCEPTION_H

#include "Exception.h"

namespace hierhin {
namespace ex {

class PropertyException : public Exception
{
public:
    PropertyException(const QString &name);

    QByteArray cause() const override {
        return QByteArray("unknown set property exception");
    }

    QString name() const;
    void setName(const QString &name);

private:
    QString _name;
};

} // namespace ex
} // namespace hierhin

#endif // HIERHINPROPERTYEXCEPTION_H

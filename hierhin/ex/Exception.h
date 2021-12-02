#ifndef HIERHIN_EXCEPTION_H
#define HIERHIN_EXCEPTION_H

#include <QException>
#include <QObject>

namespace hierhin {
namespace ex {

class Exception : public QException
{
public:
    Exception();

    void raise() const override { throw *this; }
    Exception *clone() const override { return new Exception(*this); }

    virtual QString cause() const {
        return QObject::tr("unknown hierhin lib exception");
    }
};

} // namespace ex
} // namespace hierhin

#endif // HIERHIN_EXCEPTION_H

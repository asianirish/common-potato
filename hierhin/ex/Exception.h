#ifndef HIERHIN_EXCEPTION_H
#define HIERHIN_EXCEPTION_H

#include <QException>

namespace hierhin {
namespace ex {

class Exception : public QException
{
public:
    Exception();

    void raise() const override { throw *this; }
    Exception *clone() const override { return new Exception(*this); }

    virtual QByteArray cause() const {
        return QByteArray("unknown hierhin lib exception");
    }
};

} // namespace ex
} // namespace hierhin

#endif // HIERHIN_EXCEPTION_H

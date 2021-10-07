#ifndef HI_EXCEPTION_H
#define HI_EXCEPTION_H

#include <QException>

namespace hi {
namespace ex {

class Exception : public QException
{
public:
    Exception();

    void raise() const override { throw *this; }
    Exception *clone() const override { return new Exception(*this); }

    virtual QByteArray cause() const {
        return QByteArray("unknown hi lib exception");
    }
};

} // namespace ex
} // namespace hi

#endif // HI_EXCEPTION_H

#ifndef HIERHIN_EXCEPTION_H
#define HIERHIN_EXCEPTION_H

#include <QException>
#include <QObject>

#include <QCoreApplication>

namespace hierhin {
namespace ex {

class Exception : public QException
{
    Q_DECLARE_TR_FUNCTIONS(ex)
public:
    Exception();

    void raise() const override { throw *this; }
    Exception *clone() const override { return new Exception(*this); }

    virtual QString cause() const {
        return tr("unknown hierhin lib exception");
    }
};

} // namespace ex
} // namespace hierhin

#endif // HIERHIN_EXCEPTION_H

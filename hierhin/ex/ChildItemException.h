#ifndef HIERHIN_EXCHILDITEMEXCEPTION_H
#define HIERHIN_EXCHILDITEMEXCEPTION_H

#include "Exception.h"

namespace hierhin {
namespace ex {

class ChildItemException : public Exception
{
public:
    ChildItemException();

    QString cause() const override {
        return QObject::tr("unknown child item exception");
    }
};

} //namespace ex
} // namespace hierhin

#endif // HIERHIN_EXCHILDITEMEXCEPTION_H

#ifndef SAYHICONTEXTSETTER_H
#define SAYHICONTEXTSETTER_H

#include "SayHi.h"

#include <menu/ContextSetter.h>

class SayHiContextSetter : public menu::ContextSetter
{
public:
    SayHiContextSetter();

    SayHiContextSetter(SayHi::HI_TYPE hiType);

    void setActionContext(menu::Action *action) override;

private:
    SayHi::HI_TYPE _hiType;
};

#endif // SAYHICONTEXTSETTER_H

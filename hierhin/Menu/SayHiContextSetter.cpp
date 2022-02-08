#include "SayHiContextSetter.h"

SayHiContextSetter::SayHiContextSetter()
{

}

SayHiContextSetter::SayHiContextSetter(SayHi::HI_TYPE hiType)
{
    _hiType = hiType;
}

void SayHiContextSetter::setActionContext(menu::Action *action)
{
    auto sayHi = dynamic_cast<SayHi *>(action);

    if (sayHi) {
        sayHi->setHiType(_hiType);
    }
}

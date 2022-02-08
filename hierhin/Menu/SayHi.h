#ifndef SAYHI_H
#define SAYHI_H

#include "SayHi.h"

#include <menu/SimpleAction.h>

class SayHi : public menu::SimpleAction
{
public:
    SayHi();

    enum HI_TYPE {
        HI,
        HELLO,
        GOOD_DAY
    };

    HI_TYPE hiType() const;
    void setHiType(HI_TYPE newHiType);

protected:
    QVariant simplyAct(const QVariantList &args) override;

private:
    HI_TYPE _hiType;

    menu::def::ActionDef actionDef() const override {
        return menu::def::ActionDef();
    }
};

#endif // SAYHI_H

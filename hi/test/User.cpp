#include "User.h"

#include <hi/val/Length.h> //name
#include <hi/val/MoreThanOrEqualTo.h> //age
#include <hi/val/LessThan.h> //temperature
#include <hi/val/Email.h>
#include <hi/val/Phone.h>
#include <hi/val/List.h> //language

using namespace hi;
using namespace hi::val;

namespace test {

User::User(QObject *parent) : hi::Item(parent)
{

}

QMap<QString, hi::FieldDef> User::fieldDefsSpecific() const
{
    QMap<QString, FieldDef> defMap;

    {
        FieldDef def;
        ValidatorPtr val = ValidatorPtr(new Length(1,18));
        def.addValidator(val);
        def.setDefaultValue("anonymous");
        defMap.insert("name", def);
    }
    {
        FieldDef def;
        ValidatorPtr val = ValidatorPtr(new MoreThanOrEqualTo(18));
        def.addValidator(val);
        defMap.insert("age", def);
    }
    {
        FieldDef def;
        ValidatorPtr val = ValidatorPtr(new LessThan(36.9));
        def.addValidator(val);
        def.setDefaultValue(36.6);
        defMap.insert("temperature", def);
    }

    {
        FieldDef def;
        ValidatorPtr val = ValidatorPtr(new Email());
        def.addValidator(val);
        defMap.insert("email", def);
    }
    {
        FieldDef def;
        ValidatorPtr val = ValidatorPtr(new Phone());
        def.addValidator(val);
        defMap.insert("phone", def);
    }

    {
        FieldDef def;
        ValidatorPtr val = ValidatorPtr(new List(QVariantList{"en","sv","tr","ru"}));
        def.addValidator(val);
        defMap.insert("language", def);
    }

    return defMap;
}

} // namespace test

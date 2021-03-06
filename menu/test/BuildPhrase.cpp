#include "BuildPhrase.h"

namespace menu {
namespace test {

BuildPhrase::BuildPhrase()
{

}

QVariant BuildPhrase::simplyAct(const QVariantList &args)
{
    QString retStr = QString("%1 %2 y.o. from %3 likes %4").arg(args.at(0).toString(),
                                                                args.at(1).toString(),
                                                                args.at(2).toString(),
                                                                args.at(3).toString());
    return retStr;
}

def::ActionDef BuildPhrase::actionDef() const
{
    //implied order: name, age, city, food/drink
    def::ArgDef nameDef;
    nameDef.setName("name");
    def::ArgDef ageDef;
    ageDef.setName("age");
    def::ArgDef cityDef;
    cityDef.setName("city");
    def::ArgDef foodDef;
    foodDef.setName("food");

    def::ActionDef actionDef;
    actionDef.setArgMinNum(4);
    actionDef.setArgMaxNum(4);

    actionDef.addArgDef(nameDef);
    actionDef.addArgDef(ageDef);
    actionDef.addArgDef(cityDef);
    actionDef.addArgDef(foodDef);

    return actionDef;
}

} // namespace test
} // namespace menu

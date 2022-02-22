#ifndef MENU_TEST_BUILDPHRASE_H
#define MENU_TEST_BUILDPHRASE_H

#include "menu/SimpleAction.h"

namespace menu {
namespace test {

/**
 * @brief The BuildPhrase class
 * generates a phrases like "Donnchadh 40 y.o. from Dublin likes beer"
 * to test named args
 * use (json): {"action":"phrase", "args":{"name":"Donnchadh","age":40,"city":"Dublin","food":"beer"}}
 */
class BuildPhrase : public SimpleAction
{
public:
    BuildPhrase();

protected:

    QVariant simplyAct(const QVariantList &args, const menu::TaskId &taskId) override;

private:
    def::ActionDef actionDef() const override;
};

} // namespace test
} // namespace menu

#endif // MENU_TEST_BUILDPHRASE_H

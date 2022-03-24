#include "CallChildren.h"
#include "../Node.h"
#include "menu/Redirector.h"

#include <QDebug>

namespace hierhin {
namespace sys {

CallChildren::CallChildren()
{

}

menu::def::ActionDef CallChildren::actionDef() const
{
    menu::def::ActionDef def;
    def.setArgMinNum(1);

    return def;
}

QVariant CallChildren::actNodeImpl(const QVariantList &args, Node *node)
{
    auto children = node->children();
    auto innerArgs = args;
    auto innerMethod = innerArgs.takeFirst().toString();
    QVariantList results;
    QString foldMethodName;

    if (!innerArgs.isEmpty()) {
        foldMethodName = innerArgs.takeFirst().toString();
    }

    for (auto &child : children) {
        auto result = child->execute(innerMethod, innerArgs);

        if (!result.isError()) {
            results.append(result.value());
        }
    }

    if (!foldMethodName.isEmpty()) {
        Action *action = potato_util::Factory<Action>::create("menu::hof::Fold");
        //TODO: delete action on complete (?)

        auto result = action->act(results);

        //TODO: if (!result.isError())
        return result.value();
    }

    return true;
}

} // namespace sys
} // namespace hierhin

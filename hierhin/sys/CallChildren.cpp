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
    QString combFunc;

    if (!innerArgs.isEmpty()) {
        combFunc = innerArgs.takeFirst().toString();
    }

    for (auto &child : children) {
        auto result = child->execute(innerMethod, innerArgs);

        if (!result.isError()) {
            results.append(result.value());
        }
    }

    if (!combFunc.isEmpty()) {
        QVariantList foldArgs;
        foldArgs.append(combFunc);
        foldArgs.append(results);
        return SimpleAction::simpleAct("menu::hof::Fold", foldArgs);
    }

    return true;
}

} // namespace sys
} // namespace hierhin

#include "JsonCommandTranslator.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

namespace menu {

JsonCommandTranslator::JsonCommandTranslator()
{

}

CommandInfo JsonCommandTranslator::translate(const QString &commandString) const
{
    CommandInfo ci;

    QJsonParseError err;
    QJsonDocument jdoc = QJsonDocument::fromJson(commandString.toLatin1(), &err);

    if (err.error != QJsonParseError::NoError) {
        return CommandInfo(); //TODO: use Error
    }

    auto rootObject = jdoc.object();

    if (rootObject.isEmpty()) {
        return CommandInfo(); //TODO: use Error
    }

    QJsonValue action = rootObject.value("action"); //TODO: const

    ci.setName(action.toString());

    QJsonValue argsValue = rootObject.value("args"); //TODO: const

    if (argsValue.isArray()) {
        auto args = argsValue.toArray().toVariantList();
        ci.setArgs(args);
    } else if (argsValue.isObject()) {
        //TODO: emplement
    } else {
        auto arg = argsValue.toVariant();
        ci.setArgs({arg});
    }

    return ci;
}

} // namespace menu

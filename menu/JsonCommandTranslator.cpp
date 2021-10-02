#include "JsonCommandTranslator.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

namespace menu {

const QString JsonCommandTranslator::ACTION_JSON_KEY("action");
const QString JsonCommandTranslator::ARGS_JSON_KEY("args");

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

    QJsonValue action = rootObject.value(JsonCommandTranslator::ACTION_JSON_KEY);

    ci.setName(action.toString());

    QJsonValue argsValue = rootObject.value(JsonCommandTranslator::ARGS_JSON_KEY);

    if (argsValue.isArray()) {
        auto args = argsValue.toArray().toVariantList();
        ci.setArgs(args);
    } else if (argsValue.isObject()) {
        auto namedArgs = argsValue.toObject().toVariantMap();
        ci.setNamedArgs(namedArgs);
    } else {
        auto arg = argsValue.toVariant();
        ci.setArgs({arg});
    }

    return ci;
}

} // namespace menu

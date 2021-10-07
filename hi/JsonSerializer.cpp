#include "JsonSerializer.h"

#include <QJsonObject>
#include <QJsonDocument>

namespace hi {

JsonSerializer::JsonSerializer()
{

}

QByteArray JsonSerializer::serialize(const QVariantMap &mp) const
{
    auto rootObject = QJsonObject::fromVariantMap(mp);
    QJsonDocument doc(rootObject);

    return doc.toJson();
}

QVariantMap JsonSerializer::deserializeToMap(const QByteArray &data) const
{
    auto jdoc = QJsonDocument::fromJson(data);

    return jdoc.toVariant().toMap();
}

} // namespace hi

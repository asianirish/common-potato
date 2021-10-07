#ifndef HI_JSONSERIALIZER_H
#define HI_JSONSERIALIZER_H

#include "Serializer.h"

namespace hi {

class JsonSerializer : public Serializer
{
public:
    JsonSerializer();

private:
    QByteArray serialize(const QVariantMap &mp) const override;
    QVariantMap deserializeToMap(const QByteArray &data) const override;
};

} // namespace hi

#endif // HI_JSONSERIALIZER_H

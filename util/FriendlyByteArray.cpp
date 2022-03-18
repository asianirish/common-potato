#include "FriendlyByteArray.h"

#include <QDebug>

FriendlyByteArray::FriendlyByteArray() : FriendlyByteArray(QByteArray())
{

}

FriendlyByteArray::FriendlyByteArray(const QByteArray &data) : _data(data),
    _error(false),
    _throwOnError(false)
{

}

const QByteArray &FriendlyByteArray::data() const
{
    return _data;
}

void FriendlyByteArray::setData(const QByteArray &newData)
{
    _data = newData;
}

char FriendlyByteArray::at(int i) const
{
    if (uint(i) >= uint(size())) {
        qDebug() << "ACCESS_ERROR";
        setError();
        return 0;
    }

    return _data.at(i);
}

int FriendlyByteArray::size() const
{
    return _data.size();
}

bool FriendlyByteArray::error() const
{
    return _error;
}

void FriendlyByteArray::setError(bool newError) const
{
    if (newError && _throwOnError) {
        throw QString("FriendlyByteArray ERROR") + __FILE__ + __LINE__;
    }

    _error = newError;
}

QByteArray FriendlyByteArray::mid(int pos, int len) const
{
    //it's safe
    return _data.mid(pos, len);
}

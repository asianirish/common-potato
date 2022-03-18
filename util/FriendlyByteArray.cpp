#include "FriendlyByteArray.h"

#include <QDebug>

FriendlyByteArray::FriendlyByteArray() : FriendlyByteArray(QByteArray())
{

}

FriendlyByteArray::FriendlyByteArray(const QByteArray &data) : _data(data),
    _error(false),
    _throwOnError(false),
    _message("FriendlyByteArray")
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
        qDebug() << _message << __FILE__ << __LINE__;
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
        throw _message;
    }

    _error = newError;
}

QByteArray FriendlyByteArray::mid(int pos, int len) const
{
    //it's safe
    return _data.mid(pos, len);
}

const QString &FriendlyByteArray::message() const
{
    return _message;
}

void FriendlyByteArray::setMessage(const QString &newMessage)
{
    _message = newMessage;
}

bool FriendlyByteArray::throwOnError() const
{
    return _throwOnError;
}

void FriendlyByteArray::setThrowOnError(bool newThrowOnError)
{
    _throwOnError = newThrowOnError;
}

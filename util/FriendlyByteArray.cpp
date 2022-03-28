#include "FriendlyByteArray.h"

#include <QDebug>

FriendlyByteArray::FriendlyByteArray() : FriendlyByteArray(QByteArray(), true)
{

}

FriendlyByteArray::FriendlyByteArray(const QByteArray &data, bool throwOnError) : _data(data),
    _error(throwOnError),
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

QByteArray FriendlyByteArray::left(int len) const
{
    //it's safe
    return _data.left(len);
}

QByteArray FriendlyByteArray::right(int len) const
{
    //it's safe
    return _data.right(len);
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

QByteArray FriendlyByteArray::toHex() const
{
    return _data.toHex();
}

QByteArray FriendlyByteArray::toHex(char separator) const
{
    return _data.toHex(separator);
}

FriendlyByteArray::operator QByteArray() const
{
    return _data;
}

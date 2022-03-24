#ifndef FRIENDLYBYTEARRAY_H
#define FRIENDLYBYTEARRAY_H

#include <QByteArray>
#include <QString>

//TODO: add a namespace?
class FriendlyByteArray
{
public:
    FriendlyByteArray();
    FriendlyByteArray(const QByteArray &data, bool throwOnError);

    const QByteArray &data() const;
    void setData(const QByteArray &newData);

    char at(int i) const;

    int size() const;

    QByteArray mid(int pos, int len = -1) const;

    const QString &message() const;
    void setMessage(const QString &newMessage);

    bool throwOnError() const;
    void setThrowOnError(bool newThrowOnError);

    QByteArray toHex() const;
    QByteArray toHex(char separator) const;
private:
    bool error() const;
    void setError(bool newError = true) const;

private:
    QByteArray _data;
    mutable bool _error;
    bool _throwOnError;
    QString _message;
};

#endif // FRIENDLYBYTEARRAY_H

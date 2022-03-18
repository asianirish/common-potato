#ifndef FRIENDLYBYTEARRAY_H
#define FRIENDLYBYTEARRAY_H

#include <QByteArray>

//TODO: add a namespace?
class FriendlyByteArray
{
public:
    FriendlyByteArray();
    FriendlyByteArray(const QByteArray &data);

    const QByteArray &data() const;
    void setData(const QByteArray &newData);

    char at(int i) const;

    int size() const;

    bool error() const;
    void setError(bool newError = true) const;

    QByteArray mid(int pos, int len = -1) const;

private:
    QByteArray _data;
    mutable bool _error;
    bool _throwOnError;
};

#endif // FRIENDLYBYTEARRAY_H

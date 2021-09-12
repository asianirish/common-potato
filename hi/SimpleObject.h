#ifndef SIMPLEOBJECT_H
#define SIMPLEOBJECT_H

#include <QObject>

class SimpleObject : public QObject
{
    Q_OBJECT
public:
    explicit SimpleObject(QObject *parent = nullptr);

    QString simpleName() const;
    void setSimpleName(const QString &simpleName);

signals:

private:
    QString _simpleName;

};

#endif // SIMPLEOBJECT_H

#ifndef HI_TESTA_H
#define HI_TESTA_H

#include <QObject>

namespace Hi {

class TestA : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit TestA(QObject *parent = nullptr);

signals:

};

} // namespace Hi

Q_DECLARE_METATYPE(Hi::TestA*)

#endif // HI_TESTA_H

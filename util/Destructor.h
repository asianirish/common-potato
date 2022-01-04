#ifndef UTIL_DESTRUCTOR_H
#define UTIL_DESTRUCTOR_H

#include <QCoreApplication>

namespace util {

class Destructor : public QObject
{
    Q_OBJECT
public:
    explicit Destructor(QCoreApplication *app = nullptr);

    virtual void cleanUp() = 0;

signals:

public slots:
    void onQuit();

};

} // namespace util

#endif // UTIL_DESTRUCTOR_H

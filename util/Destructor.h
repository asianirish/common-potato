#ifndef UTIL_DESTRUCTOR_H
#define UTIL_DESTRUCTOR_H

#include <QCoreApplication>

namespace potato_util {

class Destructor : public QObject
{
    Q_OBJECT
public:
    explicit Destructor(QCoreApplication *app);

protected:
    virtual void cleanUp() = 0;

signals:

public slots:
    void onQuit();

};

} // namespace potato_util


#endif // UTIL_DESTRUCTOR_H

#ifndef ACTIONLISTENER_H
#define ACTIONLISTENER_H

#include "type.h"
#include "Result.h"

#include <QObject>

namespace menu {
class ActionListener : public QObject
{
    Q_OBJECT
public:
    explicit ActionListener(QObject *parent = nullptr);

    virtual void onReadyImpl(const menu::Result &result) = 0;
    virtual void onErrorImpl(const menu::Error &error) = 0;

signals:
    void handled();
public slots:
    //for both success and error
    void onReady(const menu::Result &result);
};

} // namespace menu

#endif // ACTIONLISTENER_H

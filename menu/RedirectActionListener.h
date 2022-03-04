#ifndef MENU_REDIRECTACTIONLISTENER_H
#define MENU_REDIRECTACTIONLISTENER_H

#include "ActionListener.h"

namespace menu {

class RedirectActionListener : public ActionListener
{
public:
    explicit RedirectActionListener(QObject *parent = nullptr);

    void onReadyImpl(const menu::Result &result) override;
    void onErrorImpl(const menu::Error &err) override;

signals:
    void ready(const menu::Result &result);
    void error(const menu::Error &error);
};

} // namespace menu

#endif // MENU_REDIRECTACTIONLISTENER_H

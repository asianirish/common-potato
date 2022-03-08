#ifndef MENU_REDIRECTACTIONLISTENER_H
#define MENU_REDIRECTACTIONLISTENER_H

#include "ActionListener.h"

namespace menu {

class Redirector : public ActionListener
{
    Q_OBJECT
public:
    explicit Redirector(QObject *parent = nullptr);

    void onReadyImpl(const menu::Result &result) override;
    void onErrorImpl(const menu::Error &err) override;
};

} // namespace menu

#endif // MENU_REDIRECTACTIONLISTENER_H

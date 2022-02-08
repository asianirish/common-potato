/*
 * BASED ON https://gist.github.com/gjorquera/2576569
 * */
#pragma once

#include "Menu.h"
#include "ThisAppClassRegistry.h"

#include <QObject>

#ifdef Q_OS_WIN
#include <QWinEventNotifier>
#include <windows.h>
#else
#include <QSocketNotifier>
#endif

namespace menu {

class Menu;

class Console : public QObject
{
    Q_OBJECT;

public:
    explicit Console(const ThisAppClassRegistry* registry, Menu *menu, QObject *parent = nullptr);
    ~Console();

    void run();

    [[deprecated]] void addMenuItem(const QString &command, const QString &actionClassName);

    void showMenu() const;

    static int readInt();

signals:
    void quit();

private:
#ifdef Q_OS_WIN
    QWinEventNotifier *m_notifier;
#else
    QSocketNotifier *m_notifier;
#endif

private slots:
    void readCommand();

    void onReady(const QVariant &result, const menu::TaskId &taskId);
    void onError(const menu::Error &err);

private:
    Menu *_menu;
    void registerUniqValueClasses() const;
    void registerCommandTranslatorClasses() const;

};

} // namespace menu

#define ADD_MENU_ITEM(console, item, actionClass) REGISTER_CLASS_FOR_UTIL_FACTORY(menu::Action, actionClass); \
    console.addMenuItem(#item, #actionClass);

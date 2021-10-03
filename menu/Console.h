/*
 * BASED ON https://gist.github.com/gjorquera/2576569
 * */
#pragma once

#include "Menu.h"

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
    explicit Console(QObject *parent = nullptr);
    ~Console();

    void run();

    void addMenuItem(const QString &command, ActionPtr action);

    void showMenu() const;

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

    void onReady(const QVariant &result);
    void onError(const Error &err);

private:
    Menu *_menu;
    void registerUniqValueClasses() const;
    void registerCommandTranslatorClasses() const;

};

} // namespace menu


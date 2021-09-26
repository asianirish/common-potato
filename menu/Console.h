/*
 * BASED ON https://gist.github.com/gjorquera/2576569
 * */
#pragma once

#include "Menu.h"

#include <uniq/UuidValue.h>
#include <uniq/CompactUuidValue.h>
#include <uniq/TimeQStringValue.h>
#include <util/Factory.h>

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
    Console();

    Console(const QString &taskIdGenClassName);

    Console(const QString &taskIdGenClassName,
    const QString &commandTranslatorClassName);

    ~Console();

    void run();

    void addMenuItem(const QString &command, ActionPtr action);

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

private:
    Menu *_menu;
    void registerUniqValue() const;

};

} // namespace menu


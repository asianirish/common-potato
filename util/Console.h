/*
 * BASED ON https://gist.github.com/gjorquera/2576569
 * */
#pragma once

#include <QObject>

#ifdef Q_OS_WIN
#include <QWinEventNotifier>
#include <windows.h>
#else
#include <QSocketNotifier>
#endif

namespace util {

class Console : public QObject
{
    Q_OBJECT;

public:
    Console();

    void run();

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
};

} // namespace util


/*
 * BASED ON https://gist.github.com/gjorquera/2576569
 * */
#pragma once

#include <QObject>
#include <QSocketNotifier>
#include <iostream>

class Console : public QObject
{
    Q_OBJECT;

public:
    Console();

    void run();

signals:
    void quit();

private:
    QSocketNotifier *m_notifier;

private slots:
    void readCommand();
};


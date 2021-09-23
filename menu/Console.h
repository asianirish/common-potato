/*
 * BASED ON https://gist.github.com/gjorquera/2576569
 * */
#pragma once

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
    static QString DEFAULT_TASK_ID_GENERATOR_CLASS_NAME;

    Console();

    ~Console();

    void run();

    QString uniqValueClassName() const;
    void setUniqValueClassName(const QString &uniqValueClassName);

    uniq::Value<QString> *taskIdGenerator() const;

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
    mutable uniq::Value<QString> *_taskIdGenerator;
    QString _uniqValueClassName;

    void registerUniqValue() const;

    uniq::Value<QString> *createTaskIdGenerator() const;
};

} // namespace menu


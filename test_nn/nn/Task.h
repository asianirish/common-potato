#ifndef TASK_H
#define TASK_H

#include <QObject>

class Task : public QObject
{
    Q_OBJECT
public:
    explicit Task(QObject *parent = nullptr);

private:
    double dRand(double dMin = -1., double dMax = 1.) const;

public slots:
    void run();

signals:

    void quit();

};

#endif // TASK_H

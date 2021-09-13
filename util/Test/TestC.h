#ifndef HI_TESTC_H
#define HI_TESTC_H

#include "TestB.h"

namespace Hi {

class TestC : public TestB
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit TestC(QObject *parent = nullptr);
};

} // namespace Hi

Q_DECLARE_METATYPE(Hi::TestC*)

#endif // HI_TESTC_H

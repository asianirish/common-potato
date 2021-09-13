#ifndef HI_TESTB_H
#define HI_TESTB_H

#include "TestA.h"

namespace Hi {

class TestB : public TestA
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit TestB(QObject *parent = nullptr);
};

} // namespace Hi

Q_DECLARE_METATYPE(Hi::TestB*)

#endif // HI_TESTB_H

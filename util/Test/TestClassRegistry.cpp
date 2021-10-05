#include "TestClassRegistry.h"

#include "Test/TestA.h"
#include "Test/TestB.h"
#include "Test/TestC.h"

#include <QObject>

TestClassRegistry::TestClassRegistry()
{

}

void TestClassRegistry::registerAllClasses() const
{
    REGISTER_CLASS_FOR_UTIL_FACTORY(QObject, Hi::TestA);
    REGISTER_CLASS_FOR_UTIL_FACTORY(QObject, Hi::TestB);
    REGISTER_CLASS_FOR_UTIL_FACTORY(QObject, Hi::TestC);
}

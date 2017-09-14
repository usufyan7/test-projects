#include <iostream>
#include <string>
#include <list>
#include <C:/Users/umers/Documents/Visual Studio 2013/Projects/CPPUnitExample/cppunit/TestCase.h>
#include <C:/Users/umers/Documents/Visual Studio 2013/Projects/CPPUnitExample/cppunit/TestFixture.h>
#include <C:/Users/umers/Documents/Visual Studio 2013/Projects/CPPUnitExample/cppunit/ui/text/TextTestRunner.h>
#include <C:/Users/umers/Documents/Visual Studio 2013/Projects/CPPUnitExample/cppunit/extensions/HelperMacros.h>
#include <C:/Users/umers/Documents/Visual Studio 2013/Projects/CPPUnitExample/cppunit/extensions/TestFactoryRegistry.h>
#include <C:/Users/umers/Documents/Visual Studio 2013/Projects/CPPUnitExample/cppunit/TestResult.h>
#include <C:/Users/umers/Documents/Visual Studio 2013/Projects/CPPUnitExample/cppunit/TestResultCollector.h>
#include <C:/Users/umers/Documents/Visual Studio 2013/Projects/CPPUnitExample/cppunit/TestRunner.h>
#include <C:/Users/umers/Documents/Visual Studio 2013/Projects/CPPUnitExample/cppunit/BriefTestProgressListener.h>
#include <C:/Users/umers/Documents/Visual Studio 2013/Projects/CPPUnitExample/cppunit/CompilerOutputter.h>
#include <C:/Users/umers/Documents/Visual Studio 2013/Projects/CPPUnitExample/cppunit/XmlOutputter.h>
#include "BasicMath.h"

using namespace CppUnit;
using namespace std;

//-----------------------------------------------------------------------------

class TestBasicMath : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(TestBasicMath);
	CPPUNIT_TEST(testAddition);
	CPPUNIT_TEST(testMultiply);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp(void);
	void tearDown(void);

protected:
	void testAddition(void);
	void testMultiply(void);

private:

	CBasicMath *mTestObj;
};

//-----------------------------------------------------------------------------

void
TestBasicMath::testAddition(void)
{
	CPPUNIT_ASSERT(5 == mTestObj->Addition(2, 3));
}

void
TestBasicMath::testMultiply(void)
{
	CPPUNIT_ASSERT(6 == mTestObj->Multiply(2, 3));
}

void TestBasicMath::setUp(void)
{
	mTestObj = new CBasicMath();
}

void TestBasicMath::tearDown(void)
{
	delete mTestObj;
}

//-----------------------------------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION(TestBasicMath);

int main(int argc, char* argv[])
{
	// informs test-listener about testresults
	CPPUNIT_NS::TestResult testresult;

	// register listener for collecting the test-results
	CPPUNIT_NS::TestResultCollector collectedresults;
	testresult.addListener(&collectedresults);

	// register listener for per-test progress output
	CPPUNIT_NS::BriefTestProgressListener progress;
	testresult.addListener(&progress);

	// insert test-suite at test-runner by registry
	CPPUNIT_NS::TestRunner testrunner;
	testrunner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
	testrunner.run(testresult);

	// output results in compiler-format
	CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
	compileroutputter.write();

	// Output XML for Jenkins CPPunit plugin la la land
	ofstream xmlFileOut("C:/Users/umers/Documents/Visual Studio 2013/Projects/CPPUnitExample/cppTestBasicMathResults.xml");
	XmlOutputter xmlOut(&collectedresults, xmlFileOut);
	xmlOut.write();

	// return 0 if tests were successful
	return collectedresults.wasSuccessful() ? 0 : 1;
}
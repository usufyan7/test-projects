#ifndef CPPUNIT_TESTSUCCESSLISTENER_H
#define CPPUNIT_TESTSUCCESSLISTENER_H

#include <C:/Users/umers/Documents/Visual Studio 2013/Projects/CPPUnitExample/cppunit/SynchronizedObject.h>
#include <C:/Users/umers/Documents/Visual Studio 2013/Projects/CPPUnitExample/cppunit/TestListener.h>


CPPUNIT_NS_BEGIN


/*! \brief TestListener that checks if any test case failed.
 * \ingroup TrackingTestExecution
 */
class CPPUNIT_API TestSuccessListener : public TestListener,
                                        public SynchronizedObject
{
public:
  /*! Constructs a TestSuccessListener object.
   */
  TestSuccessListener( SynchronizationObject *syncObject = 0 );

  /// Destructor.
  virtual ~TestSuccessListener();

  virtual void reset();

  void addFailure( const TestFailure &failure );

  /// Returns whether the entire test was successful or not.
  virtual bool wasSuccessful() const;

private:
  bool m_success;
};


CPPUNIT_NS_END

#endif  // CPPUNIT_TESTSUCCESSLISTENER_H

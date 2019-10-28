#pragma once

#include "Configurable_event_listener.hxx"


#if defined( _MSC_VER )
	#pragma warning( push )
	#pragma warning( disable: 4668 ) // is not defined as a preprocessor macro, replacing with '0' for '#if/#elif'
#endif

#include "gmock/gmock.h"

#if defined( _MSC_VER )
	#pragma warning( pop )
#endif


namespace jmsf {
namespace gtest_customization {
namespace faggotorium {


class Configurable_event_listener :
	public ::testing::TestEventListener
{

private:
	::testing::TestEventListener* _event_listener;

private:
	bool _showTestCases; // Show the names of each test case.
	bool _showTestNames; // Show the names of each test.
	bool _showSuccesses; // Show each success.
	bool _showInlineFailures; // Show each failure as it occurs. You will also see it at the bottom after the full suite is run.
	bool _showTestPartFailures; // Show test part failures (FAIL() reaction)
	bool _showEnvironment; // Show the setup of the global environment.

public:
	explicit Configurable_event_listener( TestEventListener *an_event_listener );

	// virtual TestEventListener
	~Configurable_event_listener() override final;

	// virtuals TestEventListener
	void OnTestProgramStart( const ::testing::UnitTest &unit_test ) override final;
	void OnTestIterationStart( const ::testing::UnitTest &unit_test, int iteration ) override final;
	void OnEnvironmentsSetUpStart( const ::testing::UnitTest &unit_test ) override final;
	void OnEnvironmentsSetUpEnd( const ::testing::UnitTest &unit_test ) override final;
	void OnTestCaseStart( const ::testing::TestCase &test_case ) override final;
	void OnTestStart( const ::testing::TestInfo &test_info ) override final;
	void OnTestPartResult( const ::testing::TestPartResult &result ) override final;
	void OnTestEnd( const ::testing::TestInfo &test_info ) override final;
	void OnTestCaseEnd( const ::testing::TestCase &test_case ) override final;
	void OnEnvironmentsTearDownStart( const ::testing::UnitTest &unit_test ) override final;
	void OnEnvironmentsTearDownEnd( const ::testing::UnitTest &unit_test ) override final;
	void OnTestIterationEnd( const ::testing::UnitTest &unit_test, int iteration ) override final;
	void OnTestProgramEnd( const ::testing::UnitTest &unit_test ) override final;
	//~virtuals TestEventListener

};


} // namespace faggotorium
} // namespace gtest_customization
} // namespace jmsf

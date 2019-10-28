#include "Configurable_event_listener.h"


namespace jmsf {
namespace gtest_customization {
namespace faggotorium {


Configurable_event_listener::Configurable_event_listener( TestEventListener *an_event_listener )
	:
		_event_listener( an_event_listener)
{
	// add our listener, by default everything is on (the same as using the default listener)
	// here I am turning everything off so I only see the 3 lines for the result
	// (plus any failures at the end), like:

	// [==========] Running 149 tests from 53 test cases.
	// [==========] 149 tests from 53 test cases ran. (1 ms total)
	// [  PASSED  ] 149 tests.

/*/
	_showTestCases = false;
	_showTestNames = false;
	_showSuccesses = false;
	_showInlineFailures = false;
	_showTestPartFailures = false;
	_showEnvironment = false;
/*/
	_showTestCases = false; // false
	_showTestNames = false; // false
	_showSuccesses = false; // false
	_showInlineFailures = false; // false
	_showTestPartFailures = false; // false
	_showEnvironment = false; // false
//*/
}

// virtual TestEventListener
Configurable_event_listener::~Configurable_event_listener() {
	delete _event_listener;
}

// virtuals TestEventListener
void Configurable_event_listener::OnTestProgramStart( const ::testing::UnitTest &unit_test ) {
	_event_listener->OnTestProgramStart( unit_test );
}

void Configurable_event_listener::OnTestIterationStart( const ::testing::UnitTest &unit_test, const int iteration ) {
	_event_listener->OnTestIterationStart( unit_test, iteration );
}

void Configurable_event_listener::OnEnvironmentsSetUpStart( const ::testing::UnitTest &unit_test ) {
	if ( !_showEnvironment ) return;

	_event_listener->OnEnvironmentsSetUpStart( unit_test );
}

void Configurable_event_listener::OnEnvironmentsSetUpEnd( const ::testing::UnitTest &unit_test ) {
	if ( !_showEnvironment ) return;

	_event_listener->OnEnvironmentsSetUpEnd( unit_test );
}

void Configurable_event_listener::OnTestCaseStart( const ::testing::TestCase &test_case ) {
	if ( !_showTestCases ) return;

	_event_listener->OnTestCaseStart( test_case );
}

void Configurable_event_listener::OnTestStart( const ::testing::TestInfo &test_info ) {
	if ( !_showTestNames ) return;

	_event_listener->OnTestStart( test_info );
}

void Configurable_event_listener::OnTestPartResult( ::testing::TestPartResult const &result ) {
	if ( !_showTestPartFailures ) return;

	_event_listener->OnTestPartResult( result );
}

void Configurable_event_listener::OnTestEnd( ::testing::TestInfo const &test_info ) {
	if ( test_info.result()->Failed() ) {
		if ( !_showInlineFailures ) return;
	} else {
		if ( !_showSuccesses ) return;
	}

	 _event_listener->OnTestEnd( test_info );
}

void Configurable_event_listener::OnTestCaseEnd( const ::testing::TestCase &test_case ) {
	if ( !_showTestCases ) return;

	_event_listener->OnTestCaseEnd( test_case );
}

void Configurable_event_listener::OnEnvironmentsTearDownStart( const ::testing::UnitTest &unit_test ) {
	if ( !_showEnvironment ) return;

	_event_listener->OnEnvironmentsTearDownStart( unit_test );
}

void Configurable_event_listener::OnEnvironmentsTearDownEnd( const ::testing::UnitTest &unit_test ) {
	if ( !_showEnvironment ) return;

	_event_listener->OnEnvironmentsTearDownEnd( unit_test );
}

void Configurable_event_listener::OnTestIterationEnd( const ::testing::UnitTest &unit_test, const int iteration ) {
	_event_listener->OnTestIterationEnd( unit_test, iteration );
}

void Configurable_event_listener::OnTestProgramEnd( const ::testing::UnitTest &unit_test ) {
	_event_listener->OnTestProgramEnd( unit_test );
}


} // namespace faggotorium
} // namespace gtest_customization
} // namespace jmsf

#include "gtm_library.h"

#include "jmsd/tpa/gtm/modification/Writable_command_line_arguments.h"
#include "jmsd/tpa/gtm/modification/Configurable_event_listener.h"


namespace jmsd {
namespace tpa {
namespace gtm {


int gmock_main( const int argc, const char *const argv[] ) {
	{ // base and flags initialization
		::jmsd::tpa::gtm::modification::Writable_command_line_arguments writable_command_line_arguments( argc, argv );

		::testing::InitGoogleMock(
			writable_command_line_arguments.take_argument_counter(),
			writable_command_line_arguments.take_argument_string_array() );

		// Ensures that the tests pass no matter what value of --gmock_catch_leaked_mocks and --gmock_verbose the user specifies.
		testing::GMOCK_FLAG( catch_leaked_mocks ) = true;
//		testing::GTEST_FLAG( list_tests ) = true;
//		testing::GMOCK_FLAG( verbose ) = testing::internal::kWarningVerbosity;
	}

	{ // will only print errors, not successes
		testing::TestEventListeners &listeners = testing::UnitTest::GetInstance()->listeners();
		auto default_printer = listeners.Release( listeners.default_result_printer() );
		auto the_listener = new ::jmsd::tpa::gtm::modification::Configurable_event_listener( default_printer );
		listeners.Append( the_listener );
	}

	return RUN_ALL_TESTS();
}


} // namespace gtm
} // namespace tpa
} // namespace jmsd

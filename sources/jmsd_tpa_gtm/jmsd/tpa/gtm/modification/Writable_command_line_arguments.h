#pragma once

#include "Writable_command_line_arguments.hxx"


namespace jmsf {
namespace gtest_customization {
namespace faggotorium {


class Writable_command_line_arguments {

public:
	int *take_argument_counter() noexcept;
	char **take_argument_string_array() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Writable_command_line_arguments() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Writable_command_line_arguments(const int argument_counter, const char *const argument_string_array[] ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Writable_command_line_arguments( const Writable_command_line_arguments &another ) = delete;
	const Writable_command_line_arguments &operator =( const Writable_command_line_arguments &another ) = delete;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Writable_command_line_arguments( Writable_command_line_arguments &&another ) = delete;
	Writable_command_line_arguments &operator =( Writable_command_line_arguments &&another ) = delete;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	const int _argument_counter;
	int _writable_argument_counter;
	char **_writable_argument_string_array;
	char **_copy_of_writable_argument_string_array;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace faggotorium
} // namespace gtest_customization
} // namespace jmsf

#pragma once

#include <iostream>
#include <vector>
#include <string>

namespace tests
{
	class ErrorLog
	{
		std::vector<std::string> messages;
		unsigned int count;

		ErrorLog(): count( 0 ) {};

	public:
		ErrorLog( const ErrorLog& src ) = delete;
		ErrorLog& operator=( ErrorLog& rhs ) = delete;
		
		ErrorLog( ErrorLog&& src ) = default;
		ErrorLog& operator=( ErrorLog&& rhs ) = default;

		~ErrorLog() = default;

		static ErrorLog& get()
		{
			static ErrorLog log;
			return log;
		}

		void log( std::string msg )
		{
			messages.push_back( msg );
			count++;
		}

		void print( std::ostream& os = std::cout )
		{
			os << "Errors: " << count << std::endl;
			for( auto msg : messages )
				os << msg << std::endl;
		}
	};

	static ErrorLog& errorlog = ErrorLog::get();
}
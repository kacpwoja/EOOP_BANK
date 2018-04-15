#include <iostream>
#include <string>
#include <regex>
#include "../headers/Address.h"

int main()
{
	Address test;
	try
	{
		test.set( "Warszawa", "12-456", "Przytyk", "5", "71" );
	}
	catch( ... )
	{
		std::cout << "ERROR" << std::endl;
	}

	std::cout << std::regex_match( std::string( "Warszawa" ), std::regex( "\w+" ) );

	int a;
	std::cin >> a;
	return 0;
}
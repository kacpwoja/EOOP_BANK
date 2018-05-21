#include <string>
#include "TestAddress.h"
#include "../../ErrorLog.h"
#include "../../../bank/headers/Address.h"

void tests::testAddress::testAddress()
{
	testConstructors();
	testGetSet();
	testToString();
	testCompare();
	testCopyAssign();
}

void tests::testAddress::testConstructors()
{
	//Testing default constructor
	Address test;
	if( test.getCity() != std::string() )
		errorlog.log( "Address: default constructor: members not empty" );

	std::string city = "TestCity";
	std::string street = "TestStreet";
	std::string zip = "00-000";
	std::string num = "10";
	//Testing constructor with arguments
	try
	{
		Address test2( city, zip, street, num );
		if( test2.getBuildingNumber() != num || test2.getCity() != city || test2.getStreet() != street ||
			test2.getZipCode() != zip || test2.getFlatNumber() != std::string() )
			errorlog.log( "Address: constructor: members different than input" );
	}
	catch( Address::AddressError e )
	{
		std::string error = e.what();
		errorlog.log( "Address: constructor: exception thrown when data correct: " + error );
	}

	try
	{
		Address test3( "123", zip, street, num, num );
		errorlog.log( "Address: constructor: no exception thrown when city incorrect" );
	}
	catch( Address::AddressError e )
	{}

	try
	{
		Address test3( city, "aaa", street, num, num );
		errorlog.log( "Address: constructor: no exception thrown when zip incorrect" );
	}
	catch( Address::AddressError e )
	{}

	try
	{
		Address test3( city, zip, "123", num, num );
		errorlog.log( "Address: constructor: no exception thrown when street incorrect" );
	}
	catch( Address::AddressError e )
	{}

	try
	{
		Address test3( city, zip, street, "abc", num );
		errorlog.log( "Address: constructor: no exception thrown when building number incorrect" );
	}
	catch( Address::AddressError e )
	{}

	try
	{
		Address test3( city, zip, street, num, "abc" );
		errorlog.log( "Address: constructor: no exception thrown when flat number incorrect" );
	}
	catch( Address::AddressError e )
	{}
}

void tests::testAddress::testGetSet()
{
	Address test;
	std::string city = "TestCity";
	std::string street = "TestStreet";
	std::string zip = "00-000";
	std::string num = "10";
	//Testing correct arguments
	try
	{
		test.set( city, zip, street, num, num );
	}
	catch( Address::AddressError e )
	{
		std::string error = e.what();
		errorlog.log( "Address: set: exception thrown when data correct: " + error );
	}
	if( test.getCity() != city || test.getStreet() != street || test.getZipCode() != zip ||
		test.getBuildingNumber() != num || test.getFlatNumber() != num )
		errorlog.log( "Address: set: members not matching input" );
	//Testing exceptions
	try
	{
		test.set( "123", zip, street, num, num );
		errorlog.log( "Address: set: no exception thrown when city incorrect" );
	}
	catch( Address::AddressError e )
	{}

	try
	{
		test.set( city, "aaa", street, num, num );
		errorlog.log( "Address: set: no exception thrown when zip incorrect" );
	}
	catch( Address::AddressError e )
	{}

	try
	{
		test.set( city, zip, "123", num, num );
		errorlog.log( "Address: set: no exception thrown when street incorrect" );
	}
	catch( Address::AddressError e )
	{}

	try
	{
		test.set( city, zip, street, "abc", num );
		errorlog.log( "Address: set: no exception thrown when building number incorrect" );
	}
	catch( Address::AddressError e )
	{}

	try
	{
		test.set( city, zip, street, num, "abc" );
		errorlog.log( "Address: set: no exception thrown when flat number incorrect" );
	}
	catch( Address::AddressError e )
	{}
}

void tests::testAddress::testToString()
{
	Address test;
	std::string str;
	try
	{
		str = test.toString();
		errorlog.log( "Address: toString: no exception thrown when object empty" );
	}
	catch( Address::AddressError e )
	{}

	test.set( "Warszawa", "01-962", "Przytyk", "5", "71" );
	try
	{
		str = test.toString();
		if( str != "Przytyk 5/71, 01-962 Warszawa" )
			errorlog.log( "Address: toString: output doesn't match the data" );
	}
	catch( Address::AddressError e )
	{
		errorlog.log( "Address: toString: exception thrown when object not empty" );
	}
}

void tests::testAddress::testCopyAssign()
{
	Address test( "Warszawa", "01-962", "Przytyk", "5", "71" );
	Address copy( test );
	Address assign;
	assign = test;

	if( test != copy )
		errorlog.log( "Address: copy constructor: operator!= test error" );

	if( test != assign )
		errorlog.log( "Address: operator=: operator!= test error" );
}

void tests::testAddress::testCompare()
{
	Address test( "Warszawa", "01-962", "Przytyk", "5", "71" );
	Address test2( "Warszawa", "01-962", "Przytyk", "5", "70" );

	if( test == test2 )
		errorlog.log( "Address: operator== error" );

	test2.set( "Warszawa", "01-962", "Przytyk", "5", "71" );

	if( test != test2 )
		errorlog.log( "Address: operator!= error" );
}

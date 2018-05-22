#include "TestContainers.h"
#include "../../ErrorLog.h"
#include "../../../bank/headers/MainContainers.h"

void tests::testContainers::testContainers()
{
	testBL::testConstructors();
	testBL::testBanks();
	testPL::testConstructors();
	testPL::testClients();
	testPL::testEmployees();
}

void tests::testContainers::testPL::testConstructors()
{
	PeopleList test;
	if( !test.getPeople().empty() )
		errorlog.log( "PeopleList: constructor: list not empty" );
}

void tests::testContainers::testPL::testClients()
{
	PeopleList test;
	//Correct add
	try
	{
		test.addClient( "98031004973" );
		if( test.getPeople().empty() )
			errorlog.log( "PeopleList: addClient: list of people empty" );
	}
	catch( PeopleList::Error e )
	{
		std::string error = e.what();
		errorlog.log( "PeopleList: addClient: unexpected exception thrown" );
	}
	//Incorrect add
	try
	{
		test.addClient( "98031004973" );
		errorlog.log( "PeopleList: addClient: exception not thrown" );
	}
	catch( PeopleList::Error e )
	{}
	//Incorrect remove
	try
	{
		test.removePerson( "98031004678" );
		errorlog.log( "PeopleList: removePerson: exception not thrown" );
	}
	catch( PeopleList::Error e )
	{}
	//Correct remove
	try
	{
		test.removePerson( "98031004973" );
		if( !test.getPeople().empty() )
			errorlog.log( "PeopleList: removePerson: list of people not empty" );
	}
	catch( PeopleList::Error e )
	{
		std::string error = e.what();
		errorlog.log( "PeopleList: removePerson: unexpected exception thrown" );
	}
}

void tests::testContainers::testPL::testEmployees()
{
	PeopleList test;
	//Correct add
	try
	{
		test.addEmployee( "98031004973" );
		if( test.getPeople().empty() )
			errorlog.log( "PeopleList: addEmployee: list of people empty" );
	}
	catch( PeopleList::Error e )
	{
		std::string error = e.what();
		errorlog.log( "PeopleList: addEmployee: unexpected exception thrown" );
	}
	//Incorrect add
	try
	{
		test.addEmployee( "98031004973" );
		errorlog.log( "PeopleList: removePerson: exception not thrown" );
	}
	catch( PeopleList::Error e )
	{
	}
	//Incorrect remove
	try
	{
		test.removePerson( "98031004678" );
		errorlog.log( "PeopleList: removePerson: exception not thrown" );
	}
	catch( PeopleList::Error e )
	{}
	//Correct remove
	try
	{
		test.removePerson( "98031004973" );
		if( !test.getPeople().empty() )
			errorlog.log( "PeopleList: removePerson: list of people not empty" );
	}
	catch( PeopleList::Error e )
	{
		std::string error = e.what();
		errorlog.log( "PeopleList: removePerson: unexpected exception thrown" );
	}
}

void tests::testContainers::testBL::testConstructors()
{
	BankList test;
	if( !test.getBanks().empty() )
		errorlog.log( "BankList: constructor: list of banks not empty" );
}

void tests::testContainers::testBL::testBanks()
{
	BankList test;
	//correct add
	try
	{
		test.addBank( "Bank" );
		if( test.getBanks().empty() )
			errorlog.log( "BankList: addBank: list of banks empty" );
	}
	catch( BankList::Error e )
	{
		std::string error = e.what();
		errorlog.log( "BankList: addBank: unexpected exception thrown" );
	}
	//incorrect add
	try
	{
		test.addBank( "Bank" );
		errorlog.log( "BankList: addBank: no exception thrown" );
	}
	catch( BankList::Error e )
	{}
	//incorrect remove
	try
	{
		test.removeBank( "BBBB" );
		errorlog.log( "BankList: removeBank: no exception thrown" );
	}
	catch( BankList::Error e )
	{}
	//correct remove
	try
	{
		test.removeBank( "Bank" );
		if( !test.getBanks().empty() )
			errorlog.log( "Banklist: removeBank: list of banks not empty" );
	}
	catch( BankList::Error e )
	{
		std::string error = e.what();
		errorlog.log( "BankList: removeBank: unexpected exception thrown" );
	}
}

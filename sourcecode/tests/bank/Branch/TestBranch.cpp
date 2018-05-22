#include "TestBranch.h"
#include "../../ErrorLog.h"
#include "../../../bank/headers/Branch.h"
#include "../../../bank/headers/Address.h"
#include "../../../bank/headers/Employee.h"

void tests::testBranch::testBranch()
{
	testConstructors();
	testAccounts();
	testEmploying();
}

void tests::testBranch::testConstructors()
{
	Bank::Branch test( "ABC" );
	//test constructor
	if( test.getID() != "ABC" )
		errorlog.log( "Branch: constructor: wrong ID value" );
	if( test.getAddress() != Address() )
		errorlog.log( "Branch: constructor: wrong Address value" );
	if( !test.getAccounts().empty() )
		errorlog.log( "Branch: constructor: account list not empty" );
	if( !test.getClients().empty() )
		errorlog.log( "Branch: constructor: clients list not empty" );
	if( !test.getEmployees().empty() )
		errorlog.log( "Branch: constructor: employees list not empty" );
	//test destructor
	Employee emp( "98031004973" );
	Bank::Branch* test2 = new Bank::Branch( "CDE" );
	test2->hire( &emp, 3000, 20 );
	delete test2;
	if( !emp.getPositions().empty() )
		errorlog.log( "Branch: destructor: employees position list not empty" );
}

void tests::testBranch::testAccounts()
{
	//Correct adding
	//Incorrect adding
	//Incorrect removal
	//Correct removal
}

void tests::testBranch::testEmploying()
{
	Bank::Branch test( "ABC" );
	Employee emp( "98031004973" );
	//Correct adding
	try
	{
		test.hire( &emp, 3000, 10 );
		if( test.getEmployees().front() != &emp )
			errorlog.log( "Branch: hire: employee not on employee lsit" );
		if( emp.getPositions().front().employer != &test )
			errorlog.log( "Branch: hire: branch not on employee's position list" );
	}
	catch( Bank::Branch::BranchError e )
	{
		std::string error = e.what();
		errorlog.log( "Branch: hire: unexpected exception thrown: " + error );
	}
	//Incorrect adding
	try
	{
		test.hire( &emp, 2000, 8 );
		errorlog.log( "Branch: hire: no exception thrown" );
	}
	catch( Bank::Branch::BranchError e )
	{}
	//Incorrect removal
	Employee inc( "98101076321" );
	try
	{
		test.fire( &inc );
		errorlog.log( "Branch: fire: no exception thrown" );
	}
	catch( Bank::Branch::BranchError e )
	{}
	//Correct removal
	try
	{
		test.fire( &emp );
		if( !test.getEmployees().empty() )
			errorlog.log( "Branch: fire: employee list not empty" );
		if( !emp.getPositions().empty() )
			errorlog.log( "Branch: fire: employee's position list not empty" );
	}
	catch( Bank::Branch::BranchError e )
	{
		std::string error = e.what();
		errorlog.log( "Branch: fire: unexpected exception thrown" );
	}
}

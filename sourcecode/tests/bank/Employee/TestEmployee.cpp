#include "TestEmployee.h"
#include "../../ErrorLog.h"
#include "../../../bank/headers/Employee.h"
#include "../../../bank/headers/Branch.h"

void tests::testEmployee::testEmployee()
{
	testConstructors();
	testJobs();
}

void tests::testEmployee::testConstructors()
{
	Employee test( "98031004973" );
	if( test.getEarnings() != 0 )
		errorlog.log( "Employee: constructor: wrong earnings value" );
	if( test.getHours() != 0 )
		errorlog.log( "Employee: constructor: wrong hours value" );
	if( !test.getPositions().empty() )
		errorlog.log( "Employee: constructor: list of positions not empty" );
	//Destructor test
	Bank::Branch br( "AFF" );
	Employee *test2 = new Employee( "98031004973" );
	test2->newJob( &br, 20, 8 );
	delete test2;
	if( !br.getEmployees().empty() )
		errorlog.log( "Employee: destructor: not deleted from employer" );
}

void tests::testEmployee::testJobs()
{
	Bank::Branch br( "AFF" );
	Employee test( "98031004973" );
	//Correct adding
	try
	{
		test.newJob( &br, 30, 8 );
		if( test.getPositions().size() != 1 )
			errorlog.log( "Emploee: newJob: uncorrect size of positions list" );
		if( test.getEarnings() != 30 )
			errorlog.log( "Employee: newJob: uncorrect Earnings value" );
		if( test.getHours() != 8 )
			errorlog.log( "Employee: newJob: uncrrect Hours value" );
		if( br.getEmployees().front() != &test )
			errorlog.log( "Employee: newJob: not present on branch's list" );
	}
	catch( Employee::EmployeeError e )
	{
		std::string error = e.what();
		errorlog.log( "Employee: newJob: unexpected exception thrown: " + error );
	}
	//Incorrect adding
	try
	{
		test.newJob( &br, 24, 6 );
		errorlog.log( "Employee: newJob: no exception thrown when incorrect" );
	}
	catch( Employee::EmployeeError e )
	{}
	//Incorrect removal
	Bank::Branch inc( "CCC" );
	try
	{
		test.quit( &inc );
		errorlog.log( "Employee: quit: no exception thrown when incorrect" );
	}
	catch( Employee::EmployeeError e )
	{}
	//Correct removal
	try
	{
		test.quit( &br );
		if( !test.getPositions().empty() )
			errorlog.log( "Employee: quit: incorrect size of positions lift" );
		if( test.getEarnings() != 0 )
			errorlog.log( "Employee: quir: incorrect Earnings value" );
		if( test.getHours() != 0 )
			errorlog.log( "Employee: quit: incorrect Hours value" );
		if( !br.getEmployees().empty() )
			errorlog.log( "Employee: quit: branch's list of employees not empty" );
	}
	catch( Employee::EmployeeError e )
	{
		std::string error = e.what();
		errorlog.log( "Employee: quit: unexpected exception thrown: " + error );
	}
}

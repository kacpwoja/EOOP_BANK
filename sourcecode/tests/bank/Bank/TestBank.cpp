#include <string>
#include "TestBank.h"
#include "../../ErrorLog.h"
#include "../../../bank/headers/Bank.h"

void tests::testBank::testBank()
{
	testConstructors();
	testBranches();
}

void tests::testBank::testConstructors()
{
	Bank test( "Super Bank" );
	if( !test.getBranches().empty() )
		errorlog.log( "Bank: constructor: branches not empty" );
}

void tests::testBank::testBranches()
{
	Bank test( "Super Bank" );
	//correct addition
	try
	{
		test.newBranch( "ABC" );
		if( test.getBranches().empty() )
			errorlog.log( "Bank: newBranch: list of branches empty" );
	}
	catch( Bank::BankError e )
	{
		std::string error = e.what();
		errorlog.log( "Bank: newBranch: unexpected exception thrown" );
	}
	//incorrect addition
	try
	{
		test.newBranch( "ABC" );
		errorlog.log( "Bank: newBranch: exception not thrown" );
	}
	catch( Bank::BankError e )
	{}
	//incorrect removal
	try
	{
		test.removeBranch( "GGG" );
		errorlog.log( "Bank: removeBranch: exception not thrown" );
	}
	catch( Bank::BankError e )
	{}
	//correct removal
	try
	{
		test.removeBranch( "ABC" );
		if( !test.getBranches().empty() )
			errorlog.log( "Bank: removeBranch: list of branches not empty" );
	}
	catch( Bank::BankError e )
	{
		std::string error = e.what();
		errorlog.log( "Bank: removeBranch: unexpected exception thrown" );
	}
}

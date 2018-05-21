#include <string>
#include "TestAccount.h"
#include "../../ErrorLog.h"
#include "../../../bank/headers/Account.h"

void tests::testAccount::testAccount()
{
	testConstructors();
	testTransactions();
}

void tests::testAccount::testConstructors()
{
	//Checking correct number
	Client cl( "98031004973" );
	try
	{
		Account test( &cl, "11111111111111111111111111", 2000 );
		if( test.getBalance() != 2000 )
			errorlog.log( "Account: constructor: value of balance incorrect" );
		if( test.getNumber() != "11111111111111111111111111" )
			errorlog.log( "Account: constructor: value of number incorrect" );
		if( test.getOwner() != &cl )
			errorlog.log( "Account: constructor: wrong client pointer" );
	}
	//Testing incorrect
	catch( Account::AccountError e )
	{
		std::string error = e.what();
		errorlog.log( "Account: constructor: unexpected expression thrown: " + error );
	}
	try
	{
		Account test( &cl, "abc", 2000 );
		errorlog.log( "Account: constructor: exception not caught with incorrect arguments" );
	}
	catch( Account::AccountError e )
	{}
	//Testing destructor
	try
	{
		Account* test = new Account( &cl, "11111111111111111111111111", 2000 );
		delete test;
		if( !cl.getAccounts().empty() )
			errorlog.log( "Account: destructor: client account list not empty" );
	}
	catch( Address::AddressError e )
	{
		std::string error = e.what();
		errorlog.log( "Account: destructor: unexpected exception thrown: " + error );
	}
}

void tests::testAccount::testTransactions()
{
	Client cl( "98031004973" );
	Account test( &cl, "11111111111111111111111111", 2000 );
	//Test deposit
	test.deposit( 1000, "test" );
	if( test.getBalance() != 3000 )
		errorlog.log( "Account: deposit: wrong value" );
	//Test withdraw: correct value
	try
	{
		test.withdraw( 1000, "correct" );
		if( test.getBalance() != 2000 )
		{
			errorlog.log( "Account: withdraw: wrong value" );
		}
	}
	catch( Account::AccountError e )
	{
		std::string error = e.what();
		errorlog.log( "Account: withdraw: unexpected exception thrown" );
	}
	//Incorrect value
}


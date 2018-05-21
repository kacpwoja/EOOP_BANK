#include "TestClient.h"
#include "../../ErrorLog.h"
#include "../../../bank/headers/Client.h"
#include "../../../bank/headers/Account.h"

void tests::testClient::testClient()
{
	testConstructors();
	testAccounts();
}

void tests::testClient::testConstructors()
{
	Client test( "98031004973" );
	if( !test.getAccounts().empty() )
		errorlog.log( "Client: constructor: list of accounts not empty" );
	if( test.getBalance() != 0 )
		errorlog.log( "Client: constructor: balance not 0" );
}

void tests::testClient::testAccounts()
{
	Client test( "98031004873" );
	Account acc( &test, "11111111111111111111111111", 1000 );
	//Testing correct addition
	try
	{
		test.newAccount( &acc );
		if( test.getAccounts().size() != 1 )
			errorlog.log( "Client: newAccount: list of accounts too big after adding" );
		if( test.getBalance() != 1000 )
			errorlog.log( "Client: newAccount: balance value different from input" );
	}
	catch( Client::ClientError e )
	{
		std::string error = e.what();
		errorlog.log( "Client: newAccount: exception thrown unexpectedly: " + error );
	}
	//Testing incorrect addition
	try
	{
		test.newAccount( &acc );
		errorlog.log( "Client: newAccount: no exception when adding the same account" );
	}
	catch( Client::ClientError e )
	{}
	//Testing incorrect removal
	Account inc( &test, "22222222222222222222222222", 200 );
	try
	{
		test.closeAccount( &inc );
		errorlog.log( "Client: closeAccount: no exception when removing nonexisting account" );
	}
	catch( Client::ClientError e )
	{}
	//Testing correct removal
	try
	{
		test.closeAccount( &acc );
		if( !test.getAccounts().empty() )
			errorlog.log( "Client: closeAccount: list not empty after removing" );
		if( test.getBalance() != 0 )
			errorlog.log( "Client: closeAccount: wrong after removing account" );
	}
	catch( Client::ClientError e )
	{
		std::string error = e.what();
		errorlog.log( "Client: closeAccount: unexpected exception thrown" );
	}
}

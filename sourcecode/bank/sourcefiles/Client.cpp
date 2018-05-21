#include <stdexcept>
#include "../headers/Client.h"
#include "../../list/List.h"
#include "../headers/Branch.h"

Client::~Client()
{
	for( List<Account*>::iterator it = accounts.begin(); it != accounts.end(); it++ )
		closeAccount( *it );
}

void Client::newAccount( Account * acc )
{
	for( List<Account*>::const_iterator it = accounts.begin(); it != accounts.end(); it++ )
	{
		if( *it == acc )
			throw ClientError( "Account already exists!" );
	}

	accounts.push_back( acc );
	totalBalance += acc->getBalance();
}

void Client::closeAccount( Account * acc )
{
	for( List<Account*>::iterator it = accounts.begin(); it != accounts.end(); it++ )
	{
		if( *it == acc )
		{
			accounts.erase( it );
			totalBalance -= acc->getBalance();
			return;
		}
	}
	throw ClientError( "No such account exists!" );
}

void Client::update() noexcept
{
	double bal = 0;
	for( List<Account*>::iterator it = accounts.begin(); it != accounts.end(); it++ )
	{
		bal += (*it)->getBalance();
	}
	totalBalance = bal;
}

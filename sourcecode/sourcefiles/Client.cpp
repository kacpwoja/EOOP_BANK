#include <stdexcept>
#include "../headers/Client.h"
#include "../templates/List.h"
#include "../headers/Branch.h"

Client::~Client()
{
	for( List<Account*>::iterator it = accounts.begin(); it != accounts.end(); it++ )
		closeAccount( *it );
}

void Client::newAccount( Account * acc )
{
	for( List<Account*>::iterator it = accounts.begin(); it != accounts.end(); it++ )
	{
		if( *it == acc )
			throw std::invalid_argument( "Account already exists!" );
	}

	accounts.push_back( acc );
}

void Client::closeAccount( Account * acc )
{
	for( List<Account*>::iterator it = accounts.begin(); it != accounts.end(); it++ )
	{
		if( *it == acc )
		{
			accounts.erase( it );
			break;
		}
	}
	throw std::invalid_argument( "No such account exists!" );
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

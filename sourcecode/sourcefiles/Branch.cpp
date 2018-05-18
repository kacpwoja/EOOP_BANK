#include <stdexcept>
#include "../headers/Branch.h"
#include "../headers/Employee.h"
#include "../headers/Account.h"
#include "../headers/Client.h"
#include "../templates/List.h"

Bank::Branch::~Branch()
{
	for( List<Employee*>::iterator it = employees.begin(); it != employees.end(); it++ )
	{
		fire( *it );
	}
}

void Bank::Branch::newAccount( Client * client, std::string number, double balance )
{
	//TODO: check number
	Account* acc = new Account( client, number, balance );
	accounts.push_back( acc );
	client->newAccount( acc );

	for( List<Client*>::const_iterator it = clients.begin(); it != clients.end(); it++ )
	{
		if( (*it) == client )
			return;
	}

	clients.push_back( client );
}

void Bank::Branch::closeAccount( std::string number )
{
	for( List<Account*>::iterator it = accounts.begin(); it != accounts.end(); it++ )
	{
		if( (*it)->getNumber() == number )
		{
			Client* temp = (*it)->getOwner();
			temp->closeAccount( *it );
			accounts.erase( it );
			for( it = accounts.begin(); it != accounts.end(); it++ )
			{
				if( (*it)->getOwner() == temp )
					return;
			}

			for( List<Client*>::iterator itc = clients.begin(); itc != clients.end(); itc++ )
			{
				if( *itc == temp )
				{
					clients.erase( itc );
					return;
				}
			}
			throw std::invalid_argument( "Couldn't find the client!" );
		}
	}
	throw std::invalid_argument( "Number doesn't exist!" );
}

void Bank::Branch::hire( Employee* emp, double wage, int hours )
{
	for( List<Employee*>::const_iterator it = employees.begin(); it != employees.end(); it++ )
	{
		if( *it == emp )
			throw std::invalid_argument( "Person already employed at this branch!" );
	}

	employees.push_back( emp );
	emp->newJob( this, wage, hours );
}

void Bank::Branch::fire( Employee* emp )
{
	for( List<Employee*>::iterator it = employees.begin(); it != employees.end(); it++ )
	{
		if( *it == emp )
		{
			employees.erase( it );
			emp->quit( this );
		}
	}

	throw std::invalid_argument( "Person not employed at this branch!" );
}

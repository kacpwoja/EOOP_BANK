#include <stdexcept>
#include "../headers/Branch.h"
#include "../headers/Employee.h"
#include "../headers/Account.h"
#include "../headers/Client.h"
#include "../../list/List.h"

Bank::Branch::~Branch()
{
	while( !employees.empty() )
	{
		if( employees.front() != nullptr )
			fire( employees.front() );
		else
			employees.pop_front();
	}
	while( !accounts.empty() )
	{
		if( accounts.front() != nullptr )
			closeAccount( accounts.front() );
		else
			accounts.pop_front();
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

void Bank::Branch::closeAccount( Account* acc )
{
	for( List<Account*>::iterator it = accounts.begin(); it != accounts.end(); it++ )
	{
		if( *it == acc )
		{
			Client* temp = (*it)->getOwner();
			accounts.erase( it );

			delete acc;

			for( it = accounts.begin(); it != accounts.end(); it++ )
			{
				if( ( *it )->getOwner() == temp )
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
			throw BranchError( "Couldn't find the client!" );
		}
	}
	throw BranchError( "Account doesn't exist!" );
}

void Bank::Branch::hire( Employee* emp, double wage, int hours )
{
	for( List<Employee*>::const_iterator it = employees.begin(); it != employees.end(); it++ )
	{
		if( *it == emp )
			throw BranchError( "Person already employed at this branch!" );
	}

	employees.push_back( emp );
	for( auto it = emp->getPositions().begin(); it != emp->getPositions().end(); it++ )
	{
		if( it->employer == this )
			return;
	}
	emp->newJob( this, wage, hours );
}

void Bank::Branch::fire( Employee* emp )
{
	for( auto it = employees.begin(); it != employees.end(); it++ )
	{
		if( *it == emp )
		{
			employees.erase( it );
			for( auto ite = emp->getPositions().begin(); ite != emp->getPositions().end(); ite++ )
			{
				if( ite->employer == this )
				{
					emp->quit( this );
					return;
				}
			}
			return;
		}
	}

	throw BranchError( "Person not employed at this branch!" );
}

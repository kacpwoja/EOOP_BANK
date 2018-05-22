#include "../headers/Bank.h"
#include "../headers/Branch.h"
#include "../../list/List.h"

bool Bank::idExists( std::string id ) const noexcept
{
	for( List<Branch*>::const_iterator it = branches.begin(); it != branches.end(); it++ )
	{
		if( (*it)->getID() == id )
			return true;
	}
	return false;
}

Bank::~Bank()
{
	for( auto it = branches.begin(); it != branches.end(); it++ )
		delete *it;
}

void Bank::newBranch( std::string branchID )
{
	if( idExists( branchID ) )
		throw BankError( "ID already exists!" );
	
	branches.push_back( new Branch( branchID ) );
}

void Bank::newBranch( std::string branchID, Address address )
{
	if( idExists( branchID ) )
		throw BankError( "ID already exists!" );

	branches.push_back( new Branch( branchID, address ) );
}

Bank::Branch& Bank::getBranch( std::string branchID ) const
{
	for( List<Branch*>::iterator it = branches.begin(); it != branches.end(); it++ )
	{
		if( (*it)->getID() == branchID )
			return **it;
	}
	throw BankError( "Such ID doesn't exist!" );
}

void Bank::removeBranch( std::string branchID )
{
	for( List<Branch*>::iterator it = branches.begin(); it != branches.end(); it++ )
	{
		if( (*it)->getID() == branchID )
		{
			delete *it;
			branches.erase( it );
			return;
		}
	}
	throw BankError( "Such ID doesn't exist!" );
}


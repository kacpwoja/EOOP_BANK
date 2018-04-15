#include <stdexcept>
#include "../headers/Bank.h"
#include "../headers/Branch.h"
#include "../templates/List.h"

bool Bank::idExists( std::string id ) const noexcept
{
	for( List<Branch>::const_iterator it = branches.begin(); it != branches.end(); it++ )
	{
		if( it->getID() == id )
			return true;
	}
	return false;
}

void Bank::newBranch( std::string branchID )
{
	if( idExists( branchID ) )
		throw std::invalid_argument( "ID already exists!" );
	
	branches.push_back( Branch( branchID ) );
}

void Bank::newBranch( std::string branchID, Address address )
{
	if( idExists( branchID ) )
		throw std::invalid_argument( "ID already exists!" );

	branches.push_back( Branch( branchID, address ) );
}

Bank::Branch& Bank::getBranch( std::string branchID ) const
{
	for( List<Branch>::iterator it = branches.begin(); it != branches.end(); it++ )
	{
		if( it->getID() == branchID )
			return *it;
	}
	throw std::invalid_argument( "Such ID doesn't exist!" );
}

void Bank::removeBranch( std::string branchID )
{
	for( List<Branch>::iterator it = branches.begin(); it != branches.end(); it++ )
	{
		if( it->getID() == branchID )
		{
			branches.erase( it );
			return;
		}
	}
	throw std::invalid_argument( "Such ID doesn't exist!" );
}


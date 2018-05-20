#include <string>
#include <stdexcept>
#include "../headers/MainContainers.h"
#include "../headers/Address.h"
#include "../headers/Person.h"
#include "../headers/Client.h"
#include "../headers/Employee.h"
#include "../headers/Bank.h"
#include "../headers/Branch.h"

bool PeopleList::idExists( std::string id ) const noexcept
{
	for( List<Person*>::const_iterator it = people.begin(); it != people.end(); it++ )
	{
		if( (*it)->getID() == id )
		{
			return true;
		}
	}
	return false;
}

PeopleList& PeopleList::operator=( PeopleList&& rhs )
{
	if( this == &rhs )
		return *this;

	people = std::move( rhs.people );

	return *this;
}

void PeopleList::addClient( std::string id )
{
	if( idExists( id ) )
		throw std::invalid_argument( "ID already exists!" );

	Client* temp = new Client( id );
	people.push_back( temp );
}

void PeopleList::addClient( std::string nName, std::string nSurname, std::string nID, Address nAddress )
{
	if( idExists( nID ) )
		throw std::invalid_argument( "ID already exists!" );

	Client* temp = new Client( nName, nSurname, nID, nAddress );
	people.push_back( temp );
}

void PeopleList::addClient( std::string nName, std::string nSurname, std::string nID,
							std::string nCity, std::string nZip, std::string nStreet, std::string nBuildNo, std::string nFlatNo )
{
	if( idExists( nID ) )
		throw std::invalid_argument( "ID already exists!" );

	Client* temp = new Client( nName, nSurname, nID, nCity, nZip, nStreet, nBuildNo, nFlatNo );
	people.push_back( temp );
}

void PeopleList::addEmployee( std::string id )
{
	if( idExists( id ) )
		throw std::invalid_argument( "ID already exists!" );

	Employee* temp = new Employee( id );
	people.push_back( temp );
}

void PeopleList::addEmployee( std::string nName, std::string nSurname, std::string nID, Address nAddress )
{
	if( idExists( nID ) )
		throw std::invalid_argument( "ID already exists!" );

	Employee* temp = new Employee( nName, nSurname, nID, nAddress );
	people.push_back( temp );
}

void PeopleList::addEmployee( std::string nName, std::string nSurname, std::string nID,
	std::string nCity, std::string nZip, std::string nStreet, std::string nBuildNo, std::string nFlatNo )
{
	if( idExists( nID ) )
		throw std::invalid_argument( "ID already exists!" );

	Employee* temp = new Employee( nName, nSurname, nID, nCity, nZip, nStreet, nBuildNo, nFlatNo );
	people.push_back( temp );
}

void PeopleList::removePerson( std::string id )
{
	for( List<Person*>::iterator it = people.begin(); it != people.end(); it++ )
	{
		if( (*it)->getID() == id )
		{
			people.erase( it );
			return;
		}
	}

	throw std::invalid_argument( "No such ID exists!" );
}

Person & PeopleList::getPerson( std::string id )
{
	for( List<Person*>::iterator it = people.begin(); it != people.end(); it++ )
	{
		if( (*it)->getID() == id )
		{
			return **it;
		}
	}

	throw std::invalid_argument( "No such ID exists!" );
}

bool BankList::nameExists( std::string name ) const noexcept
{
	for( List<Bank*>::const_iterator it = banks.begin(); it != banks.end(); it++ )
	{
		if( (*it)->getName() == name )
			return true;
	}
	return false;
}

void BankList::addBank( std::string name )
{
	if( nameExists( name ) )
		throw std::invalid_argument( "Name already exists!" );

	banks.push_back( new Bank( name ) );
}

void BankList::removeBank( std::string name )
{
	for( List<Bank*>::const_iterator it = banks.begin(); it != banks.end(); it++ )
	{
		if( (*it)->getName() == name )
		{
			banks.erase( it );
			return;
		}
	}
	throw std::invalid_argument( "No such name exists!" );
}

Bank & BankList::getBank( std::string name )
{
	for( List<Bank*>::iterator it = banks.begin(); it != banks.end(); it++ )
	{
		if( (*it)->getName() == name )
		{
			return **it;
		}
	}
	throw std::invalid_argument( "No such name exists!" );
}

#include <stdexcept>
#include "../headers/Employee.h"
#include "../headers/Branch.h"
#include "../../list/List.h"

#define MAXHOURS 168

Employee::~Employee()
{
	for( List<Position>::iterator it = positions.begin(); it != positions.end(); it++ )
	{
		it->employer->fire( this );
	}
}

/*
Employee::Employee( Employee && src )
{
	name = std::move( src.name );
	surname = std::move( src.surname );
	id = std::move( src.id );
	address = std::move( src.address );
	totalHours = std::move( src.totalHours );
	totalEarnings = std::move( src.totalEarnings );
	positions = std::move( src.positions );
}
*/
void Employee::newJob( Bank::Branch * branch, double wage, int hours )
{
	for( List<Position>::const_iterator it = positions.begin(); it != positions.end(); it++ )
	{
		if( it->employer == branch )
			throw std::invalid_argument( "Already employed at this branch!" );
	}
	if( totalHours + hours >= MAXHOURS )
		throw std::invalid_argument( "Too many hours!" );

	Position temp;
	temp.employer = branch;
	temp.wage = wage;
	temp.hours = hours;
	positions.push_back( temp );

	totalEarnings += wage;
	totalHours += hours;
}

void Employee::quit( Bank::Branch * branch )
{
	for( List<Position>::iterator it = positions.begin(); it != positions.end(); it++ )
	{
		if( it->employer == branch )
		{
			totalHours -= it->hours;
			totalEarnings -= it->wage;
			positions.erase( it );
			return;
		}
	}
	throw std::invalid_argument( "Not employed at this branch!" );
}

const List<Bank::Branch*> Employee::getEmployers() const noexcept
{
	List<Bank::Branch*> out;
	for( List<Position>::const_iterator it = positions.begin(); it != positions.end(); it++ )
	{
		out.push_back( it->employer );
	}
	return out;
}

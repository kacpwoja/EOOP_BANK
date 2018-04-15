#include <stdexcept>
#include "../headers/Employee.h"
#include "../headers/Branch.h"
#include "../templates/List.h"

#define MAXHOURS 168

Employee::~Employee()
{
}

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

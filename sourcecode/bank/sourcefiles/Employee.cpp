#include <stdexcept>
#include "../headers/Employee.h"
#include "../headers/Branch.h"
#include "../../list/List.h"

#define MAXHOURS 168

Employee::~Employee()
{
	while( !positions.empty() )
	{
		quit( positions.front().employer );
	}
}

void Employee::newJob( Bank::Branch* branch, double wage, int hours )
{
	for( List<Position>::const_iterator it = positions.begin(); it != positions.end(); it++ )
	{
		if( it->employer == branch )
			throw EmployeeError( "Already employed at this branch!" );
	}
	if( totalHours + hours >= MAXHOURS )
		throw EmployeeError( "Too many hours!" );

	Position temp;
	temp.employer = branch;
	temp.wage = wage;
	temp.hours = hours;
	positions.push_back( temp );

	totalEarnings += wage;
	totalHours += hours;

	for( auto it = branch->getEmployees().begin(); it != branch->getEmployees().begin(); it++ )
	{
		if( *it == this )
			return;
	}
	branch->hire( this, wage, hours );
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
			for( auto ite = branch->getEmployees().begin(); ite != branch->getEmployees().begin(); ite++ )
			{
				if( *ite == this )
				{
					branch->fire( this );
					return;
				}
			}
			return;
		}
	}
	throw std::invalid_argument( "Not employed at this branch!" );
}
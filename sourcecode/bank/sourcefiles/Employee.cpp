#include <stdexcept>
#include "../headers/Employee.h"
#include "../headers/Branch.h"
#include "../../list/List.h"

#define MAXHOURS 168

Employee::~Employee()
{
	while( !positions.empty() )
	{
		if( positions.front().employer != nullptr )
			quit( positions.front().employer );
		else
			positions.pop_front();
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

	for( auto it = branch->getEmployees().begin(); it != branch->getEmployees().end(); it++ )
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
			for( auto ite = branch->getEmployees().begin(); ite != branch->getEmployees().end(); ite++ )
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
	throw EmployeeError( "Not employed at this branch!" );
}
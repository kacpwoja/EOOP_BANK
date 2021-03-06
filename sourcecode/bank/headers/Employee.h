#pragma once

#include <stdexcept>
#include "Person.h"
#include "Bank.h"
#include "../../list/List.h"

class Employee:
	public Person
{
public:
	struct Position
	{
		Bank::Branch* employer;
		double wage;
		int hours;
	};
private:
	List<Position> positions;
	double totalEarnings;
	int totalHours;
public:
	class EmployeeError final: std::invalid_argument
	{
	public:
		using std::invalid_argument::invalid_argument;
		using std::invalid_argument::what;
	};
	
	Employee( std::string id ):
		Person( id ), totalHours( 0 ), totalEarnings( 0 ), positions() {};
	Employee( std::string nName, std::string nSurname, std::string nID, Address nAddress ):
		Person( nName, nSurname, nID, nAddress ), totalHours( 0 ), totalEarnings( 0 ), positions() {};
	Employee( std::string nName, std::string nSurname, std::string nID,
			  std::string nCity, std::string nZip, std::string nStreet, std::string nBuildNo, std::string nFlatNo = std::string() ):
		Person( nName, nSurname, nID, nCity, nZip, nStreet, nBuildNo, nFlatNo ), totalHours( 0 ), totalEarnings( 0 ), positions() {};
	~Employee();

	Employee( const Employee& src ) = delete;
	Employee( Employee&& src ) = default;

	Employee& operator=( const Employee& rhs ) = delete;
	Employee& operator=( Employee&& rhs ) = default;

	void newJob( Bank::Branch* branch, double wage, int hours );
	void quit( Bank::Branch* branch );

	const List<Position>& getPositions() const noexcept { return positions; };
	int getHours() const noexcept { return totalHours; };
	double getEarnings() const noexcept { return totalEarnings; };
};


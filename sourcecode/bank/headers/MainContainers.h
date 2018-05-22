#pragma once

#include <string>
#include <stdexcept>
#include "../../list/List.h"
#include "Bank.h"
#include "Branch.h"
#include "Person.h"

class PeopleList
{
	List<Person*> people;

	bool idExists( std::string id ) const noexcept;
public:
	class Error final: std::invalid_argument
	{
	public:
		using std::invalid_argument::invalid_argument;
		using std::invalid_argument::what;
	};

	PeopleList(): people() {};
	~PeopleList();

	PeopleList( const PeopleList& src ) = delete;
	PeopleList( PeopleList&& src ) = default;
	PeopleList& operator=( const PeopleList& rhs ) = delete;
	PeopleList& operator=( PeopleList&& rhs ) = default;

	void addClient( std::string id );
	void addClient( std::string nName, std::string nSurname, std::string nID, Address nAddress );
	void addClient( std::string nName, std::string nSurname, std::string nID,
					std::string nCity, std::string nZip, std::string nStreet, std::string nBuildNo, std::string nFlatNo = std::string() );

	void addEmployee( std::string id );
	void addEmployee( std::string nName, std::string nSurname, std::string nID, Address nAddress );
	void addEmployee( std::string nName, std::string nSurname, std::string nID,
					  std::string nCity, std::string nZip, std::string nStreet, std::string nBuildNo, std::string nFlatNo = std::string() );

	void removePerson( std::string id );

	Person& getPerson( std::string id );
	const List<Person*>& getPeople() const noexcept { return people; };
};

class BankList
{
	List<Bank*> banks;

	bool nameExists( std::string name ) const noexcept;
public:
	class Error final: std::invalid_argument
	{
	public:
		using std::invalid_argument::invalid_argument;
		using std::invalid_argument::what;
	};

	BankList(): banks() {};
	~BankList() = default;

	BankList( const BankList& src ) = delete;
	BankList( BankList&& src ) = default;
	BankList& operator=( const BankList& rhs ) = delete;
	BankList& operator=( BankList&& rhs ) = default;

	void addBank( std::string name );
	void removeBank( std::string name );
	Bank& getBank( std::string name );

	const List<Bank*>& getBanks() const noexcept { return banks; };
};
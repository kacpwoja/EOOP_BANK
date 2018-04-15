#pragma once

#include <string>
#include "../templates/List.h"
#include "Bank.h"
#include "Branch.h"
#include "Person.h"

class PeopleList
{
	List<Person> people;

	bool idExists( std::string id ) const noexcept;
public:
	PeopleList() = default;
	~PeopleList() = default;
	PeopleList( const PeopleList& src ) = default;
	PeopleList& operator=( const PeopleList& rhs ) = default;

	void addClient( std::string id );
	void addClient( std::string nName, std::string nSurname, std::string nID, Address nAddress );
	void addClient( std::string nName, std::string nSurname, std::string nID,
					std::string nCity, std::string nZip, std::string nStreet, std::string nBuildNo, std::string nFlatNo = NULL );

	void addEmployee( std::string id );
	void addEmployee( std::string nName, std::string nSurname, std::string nID, Address nAddress );
	void addEmployee( std::string nName, std::string nSurname, std::string nID,
					  std::string nCity, std::string nZip, std::string nStreet, std::string nBuildNo, std::string nFlatNo = NULL );

	void removePerson( std::string id );

	const Person& getPerson( std::string id );
};

class BankList
{
	List<Bank> banks;

	bool nameExists( std::string name ) const noexcept;
public:
	BankList() = default;
	~BankList() = default;
	BankList( const BankList& src ) = default;
	BankList& operator=( const BankList& rhs ) = default;

	void addBank( std::string name );
	void removeBank( std::string name );
	const Bank& getBank( std::string name );
};
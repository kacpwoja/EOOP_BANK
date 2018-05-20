#pragma once

#include <string>
#include "../templates/List.h"
#include "Bank.h"
#include "Branch.h"
#include "Person.h"

class PeopleList
{
	List<Person*> people;

	bool idExists( std::string id ) const noexcept;
public:
	PeopleList(): people() {};
	~PeopleList();

	PeopleList( const PeopleList& src ) = delete;
	PeopleList( PeopleList&& src ): people() { people = std::move( src.people ); };
	PeopleList& operator=( const PeopleList& rhs ) = delete;
	PeopleList& operator=( PeopleList&& rhs );

	void addClient( std::string id );
	void addClient( std::string nName, std::string nSurname, std::string nID, Address nAddress );
	void addClient( std::string nName, std::string nSurname, std::string nID,
					std::string nCity, std::string nZip, std::string nStreet, std::string nBuildNo, std::string nFlatNo = NULL );

	void addEmployee( std::string id );
	void addEmployee( std::string nName, std::string nSurname, std::string nID, Address nAddress );
	void addEmployee( std::string nName, std::string nSurname, std::string nID,
					  std::string nCity, std::string nZip, std::string nStreet, std::string nBuildNo, std::string nFlatNo = NULL );

	void removePerson( std::string id );

	Person& getPerson( std::string id );
};

class BankList
{
	List<Bank*> banks;

	bool nameExists( std::string name ) const noexcept;
public:
	BankList(): banks() {};
	~BankList() = default;
	BankList( const BankList& src ): banks( src.banks ) {};
	BankList& operator=( const BankList& rhs ) { banks = rhs.banks; };

	void addBank( std::string name );
	void removeBank( std::string name );
	Bank& getBank( std::string name );
};
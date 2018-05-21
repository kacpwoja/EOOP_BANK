#pragma once

#include <string>
#include <stdexcept>
#include "Address.h"

class Person
{
protected:
	std::string name;
	std::string surname;
	std::string id;
	Address address;
public:
	class PersonError final: std::invalid_argument
	{
		using std::invalid_argument::invalid_argument;
		using std::invalid_argument::what;
	};

	Person() {};
	Person( std::string id );
	Person( std::string nName, std::string nSurname, std::string nID, Address nAddress );
	Person( std::string nName, std::string nSurname, std::string nID,
			std::string nCity, std::string nZip, std::string nStreet, std::string nBuildNo, std::string nFlatNo = std::string() );
	~Person() = default;

	Person( const Person& src ) = default;
	Person( Person&& src ) = default;

	Person& operator=( const Person& rhs ) = default;
	Person& operator=( Person&& rhs ) = default;

	bool operator==( const Person& rhs ) const noexcept;
	bool operator!=( const Person& rhs ) const noexcept;

	const Address& getAddress() const noexcept { return address; };
	std::string getName() const noexcept { return name; };
	std::string getSurname() const noexcept { return surname; };
	std::string getID() const noexcept { return id; };

	void setName( std::string nName, std::string nSurname );
	std::string fullName() const noexcept { return name + " " + surname; };
};


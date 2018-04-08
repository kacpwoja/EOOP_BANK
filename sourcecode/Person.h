#pragma once

#include <string>
#include "Address.h"

class Person
{
protected:
	std::string name;
	std::string surname;
	std::string id;
	Address address;
public:
	Person();
	Person( std::string nName, std::string nSurname, std::string nID, Address nAddress );
	Person( std::string nName, std::string nSurname, std::string nID,
			std::string nCity, std::string nZip, std::string nStreet, std::string nBuildNo, std::string nFlatNo = NULL );
	~Person();
	const Address& getAddress() const noexcept;
	std::string getName() const noexcept;
	std::string getSurname() const noexcept;
	std::string getID() const noexcept;
	std::string setName( std::string nName, std::string nSurname );
	std::string fullName() const noexcept;
};


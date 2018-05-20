#include <string>
#include "../headers/Person.h"

//TODO: checking correctness

Person::Person( std::string id )
{
	this->id = id;
}

Person::Person( std::string nName, std::string nSurname, std::string nID, Address nAddress )
{
	id = nID;
	name = nName;
	surname = nSurname;
	address = nAddress;
}

Person::Person( std::string nName, std::string nSurname, std::string nID, std::string nCity, std::string nZip, std::string nStreet, std::string nBuildNo, std::string nFlatNo )
{
	id = nID;
	name = nName;
	surname = nSurname;
	address = Address( nCity, nZip, nStreet, nBuildNo, nFlatNo );
}

void Person::setName( std::string nName, std::string nSurname )
{
	name = nName;
	surname = nSurname;
}

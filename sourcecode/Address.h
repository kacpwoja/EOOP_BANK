#pragma once

#include <string>

class Address
{
private:
	std::string street;
	std::string city;
	std::string zipCode;
	std::string buildingNo;
	std::string flatNo;

public:
	Address() = default;
	Address( std::string nCity, std::string nZip, std::string nStreet, std::string nBuildNo, std::string nFlatNo = NULL );
	~Address() = default;
	std::string toString() const noexcept;
	void set( std::string nCity, std::string nZip, std::string nStreet, std::string nBuildNo, std::string nFlatNo = NULL );
	std::string getStreet() const noexcept;
	std::string getCity() const noexcept;
	std::string getZipCode() const noexcept;
	std::string getBuildingNumber() const noexcept;
	std::string getFlatNumber() const noexcept;
};
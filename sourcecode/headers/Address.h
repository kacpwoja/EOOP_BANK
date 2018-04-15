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

	bool zipCorrect( std::string zip ) const noexcept;
public:
	Address() = default;
	Address( std::string nCity, std::string nZip, std::string nStreet, std::string nBuildNo, std::string nFlatNo = std::string() );
	~Address() = default;
	std::string toString() const noexcept;
	void set( std::string nCity, std::string nZip, std::string nStreet, std::string nBuildNo, std::string nFlatNo = std::string() );
	std::string getStreet() const noexcept { return street; };
	std::string getCity() const noexcept { return city; };
	std::string getZipCode() const noexcept { return zipCode; };
	std::string getBuildingNumber() const noexcept { return buildingNo; };
	std::string getFlatNumber() const noexcept { return flatNo; };
};
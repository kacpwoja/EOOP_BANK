#pragma once

#include <string>
#include <stdexcept>

class Address
{
private:
	std::string street;
	std::string city;
	std::string zipCode;
	std::string buildingNo;
	std::string flatNo;

	bool zipCorrect( std::string zip ) const noexcept;
	bool isWords( std::string in ) const noexcept;
	bool isNumber( std::string in ) const noexcept;
public:
	class AddressError final: std::invalid_argument
	{
	public:
		using std::invalid_argument::invalid_argument;
		using std::invalid_argument::what;
	};

	Address() = default;
	Address( std::string nCity, std::string nZip, std::string nStreet, std::string nBuildNo, std::string nFlatNo = std::string() );
	~Address() = default;

	Address( const Address& src ) = default;
	Address( Address&& src ) = default;

	Address& operator=( const Address& rhs ) = default;
	Address& operator=( Address&& rhs ) = default;

	bool operator==( const Address& rhs ) const noexcept;
	bool operator!=( const Address& rhs ) const noexcept;

	std::string toString() const;

	void set( std::string nCity, std::string nZip, std::string nStreet, std::string nBuildNo, std::string nFlatNo = std::string() );

	std::string getStreet() const noexcept { return street; };
	std::string getCity() const noexcept { return city; };
	std::string getZipCode() const noexcept { return zipCode; };
	std::string getBuildingNumber() const noexcept { return buildingNo; };
	std::string getFlatNumber() const noexcept { return flatNo; };
};
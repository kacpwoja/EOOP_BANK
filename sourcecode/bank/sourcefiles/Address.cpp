#include <string>
#include <regex>
#include "../headers/Address.h"

bool Address::zipCorrect( std::string zip ) const noexcept
{
	std::regex zr( "[0-9][0-9]-[0-9][0-9][0-9]" );

	return regex_match( zip, zr );
}

bool Address::isWords( std::string in ) const noexcept
{
	return true;
}

bool Address::isNumber( std::string in ) const noexcept
{
	return true;
}

Address::Address( std::string nCity, std::string nZip, std::string nStreet, std::string nBuildNo, std::string nFlatNo )
{
	if( !zipCorrect( nZip ) )
		throw AddressError( "Wrong Zip Code format!" );

	if( !isWords( nCity ) )
		throw AddressError( "City name format incorrect!" );

	if( !isWords( nStreet ) )
		throw AddressError( "Street name format incorrect!" );

	if( !isNumber( nBuildNo ) )
		throw AddressError( "Building number is not a number!" );

	if( !flatNo.empty() )
	{
		if( !isNumber( nFlatNo ) )
			throw AddressError( "Flat number is not a number!" );
	}

	zipCode = nZip;
	city = nCity;
	street = nStreet;
	buildingNo = nBuildNo;
	if( !nFlatNo.empty() )
	flatNo = nFlatNo;
}

bool Address::operator==( const Address & rhs ) const noexcept
{
	return zipCode == rhs.zipCode && city == rhs.city && street == rhs.street && buildingNo == rhs.buildingNo && flatNo == rhs.flatNo;
}

bool Address::operator!=( const Address & rhs ) const noexcept
{
	return zipCode != rhs.zipCode || city != rhs.city || street != rhs.street || buildingNo != rhs.buildingNo || flatNo != rhs.flatNo;
}

std::string Address::toString() const
{
	if( zipCode.empty() )
		throw AddressError( "Address is empty" );

	std::string out = street + " " + buildingNo;
	if( !flatNo.empty() )
		out += "/" + flatNo;
	out += ", " + zipCode + " " + city;

	return out;
}

void Address::set( std::string nCity, std::string nZip, std::string nStreet, std::string nBuildNo, std::string nFlatNo )
{
	if( !zipCorrect( nZip ) )
		throw AddressError( "Wrong Zip Code format!" );

	if( !isWords( nCity ) )
		throw AddressError( "City name format incorrect!" );

	if( !isWords( nStreet ) )
		throw AddressError( "Street name format incorrect!" );

	if( !isNumber( nBuildNo ) )
		throw AddressError( "Building number is not a number!" );

	if( !flatNo.empty() )
	{
		if( !isNumber( nFlatNo ) )
			throw AddressError( "Flat number is not a number!" );
	}


	zipCode = nZip;
	city = nCity;
	street = nStreet;
	buildingNo = nBuildNo;
	if( !nFlatNo.empty() )
		flatNo = nFlatNo;
}

#include <string>
#include <stdexcept>
#include <regex>
#include "../headers/Address.h"

bool Address::zipCorrect( std::string zip ) const noexcept
{
	std::regex zr( "[0-9][0-9]-[0-9][0-9][0-9]" );

	return regex_match( zip, zr );
}

Address::Address( std::string nCity, std::string nZip, std::string nStreet, std::string nBuildNo, std::string nFlatNo )
{
	if( !zipCorrect( nZip ) )
		throw std::invalid_argument( "Wrong Zip Code format!" );

	zipCode = nZip;
	city = nCity;
	street = nStreet;
	buildingNo = nBuildNo;
	if( !nFlatNo.empty() )
	flatNo = nFlatNo;
}

std::string Address::toString() const noexcept
{
	std::string out = street + " " + buildingNo;
	if( !flatNo.empty() )
		out += "/" + flatNo;
	out += ", " + zipCode + " " + city;

	return out;
}

void Address::set( std::string nCity, std::string nZip, std::string nStreet, std::string nBuildNo, std::string nFlatNo )
{
	if( !zipCorrect( nZip ) )
		throw std::invalid_argument( "Wrong Zip Code format!" );

	zipCode = nZip;
	city = nCity;
	street = nStreet;
	buildingNo = nBuildNo;
	if( !nFlatNo.empty() )
		flatNo = nFlatNo;
}

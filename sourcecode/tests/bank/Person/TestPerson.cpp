#include <string>
#include "TestPerson.h"
#include "../../ErrorLog.h"
#include "../../../bank/headers/Person.h"
#include "../../../bank/headers/Address.h"

void tests::testPerson::testPerson()
{
	testConstructors();
	testGetSet();
	testCompare();
	testFullName();
	testCopyAssign();
}

void tests::testPerson::testConstructors()
{
	//Testing default constructor
	{
		Person test;
		if( test.getName() != std::string() )
			errorlog.log( "Person: default constructor: members not empty" );
	}
	std::string city = "TestCity";
	std::string street = "TestStreet";
	std::string zip = "00-000";
	std::string num = "10";
	
	std::string id = "78021506345";
	std::string name = "Andrzej";
	std::string sname = "Nowak";
	
	Address ads( city, zip, street, num, num );
	//Testing id constructor
	//Correct arguments
	try
	{
		Person test( id );
		if( test.getID() != id )
			errorlog.log( "Person: id constructor: member differs from input" );
	}
	catch( Person::PersonError e )
	{
		std::string error = e.what();
		errorlog.log( "Person: id constructor: exception thrown when data correct" );
	}
	//Incorrect arguments
	try
	{
		Person test( "abc" );
		errorlog.log( "Person: id constructor: no exception thrown when id incorrect" );
	}
	catch( Person::PersonError e )
	{}

	//Testing address constructor
	//Correct arguments
	try
	{
		Person test( name, sname, id, ads );
		if( test.getID() != id || test.getName() != name || test.getSurname() != sname || test.getAddress() != ads )
			errorlog.log( "Person: address constructor: members differ from input" );
	}
	catch( Person::PersonError e )
	{
		std::string error = e.what();
		errorlog.log( "Person: address constructor: exception thrown when data correct" );
	}
	//Incorrect arguments
	try
	{
		Person test( "123", sname, id, ads );
		errorlog.log( "Person: address constructor: no exception thrown when name incorrect" );
	}
	catch( Person::PersonError e )
	{}
	try
	{
		Person test( name, "123", id, ads );
		errorlog.log( "Person: address constructor: no exception thrown when surname incorrect" );
	}
	catch( Person::PersonError e )
	{}
	try
	{
		Person test( name, sname, "abc", ads );
		errorlog.log( "Person: address constructor: no exception thrown when id incorrect" );
	}
	catch( Person::PersonError e )
	{}

	//Testing strings constructor
	//Correct arguments
	try
	{
		Person test( name, sname, id, city, zip, street, num, num );
		if( test.getID() != id || test.getName() != name || test.getSurname() != sname || test.getAddress() != ads )
			errorlog.log( "Person: strings constructor: members differ from input" );
	}
	catch( Person::PersonError e )
	{
		std::string error = e.what();
		errorlog.log( "Person: strings constructor: exception thrown when data is correct" );
	}
	//Incorrect arguments
	try
	{
		Person test( "123", sname, id, city, zip, street, num, num );
		errorlog.log( "Person: strings constructor: no exception thrown when name incorrect" );
	}
	catch( Person::PersonError e )
	{}
	try
	{
		Person test( name, "123", id, city, zip, street, num, num );
		errorlog.log( "Person: strings constructor: no exception thrown when surname incorrect" );
	}
	catch( Person::PersonError e )
	{}
	try
	{
		Person test( name, sname, "abc", city, zip, street, num, num );
		errorlog.log( "Person: strings constructor: no exception thrown when id incorrect" );
	}
	catch( Person::PersonError e )
	{}
}

void tests::testPerson::testGetSet()
{
	Person test( "98031544373" );
	std::string name = "Andrzej";
	std::string sname = "Kowalski";
	//Testing correct arguments
	try
	{
		test.setName( name, sname );
		if( test.getName() != name || test.getSurname() != sname )
			errorlog.log( "Person: set: members not matching input" );
	}
	catch( Person::PersonError e )
	{
		std::string error = e.what();
		errorlog.log( "Person: set: exception thrown when data correct: " + error );
	}
	//Testing incorrect arguments
	try
	{
		test.setName( "123", sname );
		errorlog.log( "Person: set: no exception thrown when name incorrect" );
	}
	catch( Person::PersonError e )
	{}
	try
	{
		test.setName( name, "123" );
		errorlog.log( "Person: set: no exception thrown when surname incorrect" );
	}
	catch( Person::PersonError e )
	{}
}

void tests::testPerson::testCompare()
{
	Address ads( "Warszawa", "01-962", "Przytyk", "5", "71" );
	Person test( "Andrzej", "Kowalski", "98031004973", ads );
	Person comp( "Andrzej", "Kowalski", "98031004973", ads );

	if( comp != test )
		errorlog.log( "Person: operator!= error" );

	comp.setName( "Piotr", "Nowak" );

	if( comp == test )
		errorlog.log( "Person: operator== error" );
}

void tests::testPerson::testFullName()
{
	Person test( "98031004973" );
	std::string str;
	//Testing empty
	try
	{
		str = test.fullName();
		errorlog.log( "Person: fullName: no exception thrown when no name" );
	}
	catch( Person::PersonError e )
	{}
	//Testing unempty
	test.setName( "Andrzej", "Kowalski" );
	try
	{
		str = test.fullName();
		if( str != "Andrzej Kowalski" )
			errorlog.log( "Person: fullName: output doesn't match input" );
	}
	catch( Person::PersonError e )
	{
		std::string error = e.what();
		errorlog.log( "Person: fullName: exception thrown when name exists: " + error );
	}
}

void tests::testPerson::testCopyAssign()
{
	Person test( "98031004973" );
	test.setName( "Andrzej", "Kowalski" );

	Person copy( test );
	Person assign;
	assign = test;

	if( copy != test )
		errorlog.log( "Person: copy constructor: operator!= test error" );

	if( assign != test )
		errorlog.log( "Person: operator=: operator!= test error" );
}

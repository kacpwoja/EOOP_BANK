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
	Person test;
	if( test.getName() != std::string() )
		errorlog.log( "Person: default constructor: members not empty" );


}

void tests::testPerson::testGetSet()
{
}

void tests::testPerson::testCompare()
{
}

void tests::testPerson::testFullName()
{
}

void tests::testPerson::testCopyAssign()
{
}

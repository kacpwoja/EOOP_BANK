#include "../ErrorLog.h"
#include "TestList.h"
#include "../../list/List.h"

void tests::testList::testList()
{
	testConstructors();
	testPushPop();
	testComparison();
	testCopyAssign();
	testIterator();
}

void tests::testList::testConstructors()
{
	List<int> test;
	if( !test.empty() )
		errorlog.log( "List: default constructor empty() test error" );
	if( test.size() )
		errorlog.log( "List: default constructor size() test error" );
}

void tests::testList::testComparison()
{
	List<int> test1;
	List<int> test2;
	test1.push_back( 1 );
	test2.push_back( 1 );
	if( test1 != test2 )
		errorlog.log( "List: operator!= error on same lists" );
	if( !( test1 == test2 ) )
		errorlog.log( "List: operator== error on same lists" );
	test1.push_back( 2 );
	test2.push_back( 3 );
	if( !( test1 != test2 ) )
		errorlog.log( "List: operator!= error on different lists" );
	if( test1 == test2 )
		errorlog.log( "List: operator== error on different lists" );
}

void tests::testList::testPushPop()
{
}

void tests::testList::testCopyAssign()
{
}

void tests::testList::testIterator()
{
}

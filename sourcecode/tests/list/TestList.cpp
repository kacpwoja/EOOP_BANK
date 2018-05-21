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
		errorlog.log( "List: default constructor: empty() test error" );
	if( test.size() )
		errorlog.log( "List: default constructor: size() test error" );
}

void tests::testList::testComparison()
{
	List<int> test1;
	List<int> test2;
	test1.push_back( 1 );
	test2.push_back( 1 );
	if( test1 != test2 )
		errorlog.log( "List: operator!=: error on same lists" );
	if( !( test1 == test2 ) )
		errorlog.log( "List: operator==: error on same lists" );
	test1.push_back( 2 );
	test2.push_back( 3 );
	if( !( test1 != test2 ) )
		errorlog.log( "List: operator!=: error on different lists" );
	if( test1 == test2 )
		errorlog.log( "List: operator==: error on different lists" );
}

void tests::testList::testPushPop()
{
	List<int> test;

	test.push_back( 1 );
	test.push_back( 2 );
	if( test.size() != 2 )
		errorlog.log( "List: push_back( int ): size() test error" );
	if( test.empty() )
		errorlog.log( "List: push_back( int ): empty() test error" );

	test.push_front( 3 );
	test.push_front( 4 );
	if( test.size() != 4 )
		errorlog.log( "List: push_front( int ): size() test error" );
	if( test.empty() )
		errorlog.log( "List: push_front( int ): empty() test error" );

	test.pop_back();
	if( test.size() != 3 )
		errorlog.log( "List: pop_back( int ): size() test error" );

	test.pop_front();
	if( test.size() != 2 )
		errorlog.log( "List: pop_front( int ): size() test error" );

	if( test.front() != 3 )
		errorlog.log( "List: front() test error" );
	if( test.back() != 1 )
		errorlog.log( "List: back() test error" );

	test.clear();
	if( !test.empty() )
		errorlog.log( "List: clear(): empty() test error" );
}

void tests::testList::testCopyAssign()
{
	List<int> test;
	for( int i = 0; i < 10; i++ )
		test.push_back( i );

	List<int> copy( test );
	if( copy != test )
		errorlog.log( "List: copy constructor: operator!= test error" );

	List<int> assign;
	assign = test;
	if( assign != test )
		errorlog.log( "List: operator=: operator!= test error" );

}

void tests::testList::testIterator()
{
	List<int> test;

	for( int i = 0; i < 10; i++ )
		test.push_back( i );

	List<int>::iterator it = test.begin();

	if( *it != 0 )
		errorlog.log( "List: begin(): operator* test error" );

	it++; it++;
	if( *it != 2 )
		errorlog.log( "List: iterator: operator++(post): operator* test error" );
	++it;
	if( *it != 3 )
		errorlog.log( "List: iterator: operator++(pre): operator* test error" );
	it--;
	if( *it != 2 )
		errorlog.log( "List: iterator: operator--(post): operator* test error" );
	--it;
	if( *it != 1 )
		errorlog.log( "List: iterator: operator--(pre): operator* test error" );

	if( test[5] != 5 )
		errorlog.log( "List: iterator: operator[] error: wrong value" );

	try
	{
		int i = test[ 20 ];
		errorlog.log( "List: iterator: operator[] error: no exception thrown" );
	}
	catch( List<int>::ListError e )
	{}

	List<int>::iterator it2 = test.begin();
	it2++;
	if( it2 != it )
		errorlog.log( "List: iterator: operator!= error" );
	if( !( it2 == it ) )
		errorlog.log( "List: iterator: operator== error" );

	List<int>::iterator copy( it );
	if( copy != it )
		errorlog.log( "List: iterator: copy constructor error" );

	List<int>::iterator assign = test.begin();
	assign = it;
	if( assign != it )
		errorlog.log( "List: iterator: operator= error" );
}

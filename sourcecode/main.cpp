#include <iostream>
#include <fstream>
#include "tests\TestAll.h"

int main()
{
	std::ofstream outfile;
	outfile.open( "error_log.txt" );
	tests::testAll();
	tests::errorlog.print( outfile );

	return 0;
}
#include <iostream>
#include "tests\TestAll.h"

int main()
{
	tests::testAll();
	tests::errorlog.print();

	int i;
	std::cin >> i;

	return 0;
}
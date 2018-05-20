#include "./headers/MainContainers.h"
#include <iostream>

int main()
{
	BankList banks;
	PeopleList people;
	banks.addBank( "Super Bank" );
	//Bank superb = banks.getBank( "Super Bank" );
	banks.getBank( "Super Bank" ).newBranch( "69" );
	//Bank::Branch br = superb.getBranch( "69" );
	people.addClient( "PESOL" );
	std::cerr << "1\n";
	banks.getBank( "Super Bank" ).getBranch( "69" ).newAccount( (Client*) &people.getPerson( "PESOL" ), "numbor" );
	std::cerr << "1\n";
	people.addEmployee( "ZBYCH" );
	banks.getBank( "Super Bank" ).getBranch( "69" ).hire( (Employee*)&people.getPerson( "ZBYCH" ), 200, 10 );

	int i;
	std::cin >> i;

	return 0;
}
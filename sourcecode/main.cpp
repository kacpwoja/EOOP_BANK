#include "./headers/MainContainers.h"
#include <iostream>

int main()
{
	BankList banks;
	PeopleList people;
	int i;
	std::cin >> i;
	banks.addBank( "Super Bank" );
	std::cin >> i;
	Bank superb = banks.getBank( "Super Bank" );
	superb.newBranch( "69" );
	std::cin >> i;
	Bank::Branch br = superb.getBranch( "69" );
	std::cin >> i;
	people.addClient( "PESOL" );
	std::cin >> i;
	std::cerr << "1\n";
	br.newAccount( (Client*) &people.getPerson( "PESOL" ), "numbor" );
	std::cerr << "1\n";
	std::cin >> i;
	people.addEmployee( "ZBYCH" );
	std::cin >> i;
	br.hire( (Employee*)&people.getPerson( "ZBYCH" ), 200, 10 );
	std::cin >> i;

	return 0;
}
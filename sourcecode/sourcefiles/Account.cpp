#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>
#include "../headers/Account.h"
#include "../headers/Branch.h"

#define MAXTRANSACTIONS 10

Account::~Account()
{
	client->closeAccount( this );
}

void Account::deposit( double amount, std::string title )
{
	if( amount <= 0 )
		throw std::invalid_argument( "Nonzero argument expected" );
	balance += amount;

	if( transactions.size() == MAXTRANSACTIONS )
		transactions.pop_back();

	Transaction tr;
	tr.title = title;
	tr.value = amount;
	transactions.push_front( tr );

	client->update();
}

void Account::withdraw( double amount, std::string title )
{
	if( amount <= 0 )
		throw std::invalid_argument( "Nonzero argument expected" );
	balance -= amount;

	if( transactions.size() == MAXTRANSACTIONS )
		transactions.pop_back();

	Transaction tr;
	tr.title = title;
	tr.value = -amount;
	transactions.push_front( tr );

	client->update();
}

void Account::printTransactions( std::ostream & os ) const noexcept
{
	os << "Recent transactions:" << std::endl;
	for( List<Transaction>::const_iterator it = transactions.begin(); it != transactions.end(); it++ )
	{
		os << std::setprecision( 2 ) << it->value << "\t" << it->title << std::endl;
	}
	os << "End of the list." << std::endl;
}

#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>
#include <utility>

#include "../headers/Account.h"
#include "../headers/Branch.h"
#include "../headers/Client.h"
#include "../../list/List.h"

#define MAXTRANSACTIONS 10

Account::~Account()
{
	if( client != nullptr )
	{
		for( List<Account*>::const_iterator it = client->getAccounts().begin(); it != client->getAccounts().end(); it++ )
		{
			if( *it == this )
				client->closeAccount( this );
		}
	}
}

Account::Account( Account && src )
{
	accountNumber = std::move( src.accountNumber );
	balance = std::move( src.balance );
	transactions = std::move( src.transactions );
	client = src.client;
	src.client = nullptr;
}

Account& Account::operator=( Account && rhs )
{
	if( this == &rhs )
		return *this;

	accountNumber = std::move( rhs.accountNumber );
	balance = std::move( rhs.balance );
	transactions = std::move( rhs.transactions );
	client = rhs.client;
	rhs.client = nullptr;

	return *this;
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

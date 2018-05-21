#pragma once

#include <string>
#include <iostream>
#include <stdexcept>
#include "Bank.h"
#include "Client.h"
#include "../../list/List.h"

class Client;

class Account
{
	struct Transaction
	{
		double value;
		std::string title;
	};
	std::string accountNumber;
	Client* client;
	double balance;
	List<Transaction> transactions;
public:
	class AccountError final: std::invalid_argument
	{
	public:
		using std::invalid_argument::invalid_argument;
		using std::invalid_argument::what;
	};
	Account() = delete;
	Account( Client* client, std::string number, double balance = 0 ): client( client ), balance( balance ), accountNumber( number ), transactions() {};
	~Account();

	Account( const Account& src ) = delete;
	Account( Account&& src );
	Account& operator=( const Account& rhs ) = delete;
	Account& operator=( Account&& rhs );

	double getBalance() const noexcept { return balance; };
	std::string getNumber() const noexcept { return accountNumber; };
	Client* getOwner() const noexcept { return client; };

	void deposit( double amount, std::string title = "Deposit" );
	void withdraw( double amount, std::string title = "Withdrawal" );
	void printTransactions( std::ostream& os = std::cout ) const noexcept;
};
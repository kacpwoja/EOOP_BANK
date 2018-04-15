#pragma once

#include <string>
#include <iostream>
#include "Bank.h"
#include "../headers/Client.h"
#include "../templates/List.h"

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
	Account() {};
	Account( Client* client, std::string number, double balance = 0 ): client( client ), balance( balance ), accountNumber( number ) {};
	~Account();
	double getBalance() const noexcept { return balance; };
	std::string getNumber() const noexcept { return accountNumber; };
	const Client* getOwner() const noexcept { return client; };
	void deposit( double amount, std::string title = "Deposit" );
	void withdraw( double amount, std::string title = "Withdrawal" );
	void printTransactions( std::ostream& os = std::cout ) const noexcept;
};
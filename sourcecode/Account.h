#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "Service.h"

#define MAXTRANSACTIONS 10

class Account:
	public Service
{
	struct Transaction
	{
		double value;
		std::string title;
	};

	double balance;
	std::vector<Transaction> transactions;
public:
	Account();
	Account( double nBalance );
	~Account();
	double getBalance() const noexcept;
	void deposit( double amount, std::string title = "Deposit" );
	void withdraw( double amout, std::string title = "Withdrawal" );
	void printTransactions( std::ostream& os = std::cout ) const noexcept;
	virtual void simulate() override;
};


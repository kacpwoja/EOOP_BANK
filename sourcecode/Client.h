#pragma once

#include <vector>
#include "Person.h"
#include "Service.h"

class Client:
	public Person
{
	std::vector<Service*> services;
	double totalBalance;
	double totalDebt;
	double totalDeposit;
public:
	Client();
	~Client();
	void newService( Service* );
	void closeService( Service* );
	const std::vector<Service*> getServices() const noexcept;
	double getBalance() const noexcept;
	double getDebt() const noexcept;
	double getDeposit() const noexcept;
	void update() noexcept;
};


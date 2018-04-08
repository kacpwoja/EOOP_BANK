#pragma once

#include <vector>
#include "Person.h"
#include "Bank.h"

class Employee:
	public Person
{
	std::vector<Bank::Branch*> employers;
	double totalEarnings;
	int totalHours;
public:
	Employee();
	~Employee();
	void newJob( Bank::Branch* branch );
	const std::vector<Bank::Branch*> getEmployers() const noexcept;
	int getHours() const noexcept;
	double getEarnings() const noexcept;
};


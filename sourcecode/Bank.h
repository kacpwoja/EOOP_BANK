#pragma once

#include <string>
#include <vector>
#include "Address.h"

class Bank
{
public:
	class Branch;
private:
	std::string name;
	std::vector<Branch> branches;
	double totalDeposit;
public:
	Bank() = default;
	Bank( std::string name, double deposit = 0 );
	~Bank() = default;
	void newBranch( std::string branchID );
	void newBranch( std::string branchID, Address address );
	void simulate();
};


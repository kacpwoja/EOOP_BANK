#pragma once

#include <string>
#include "Address.h"
#include "../../list/List.h"

class Bank
{
public:
	class Branch;
private:
	std::string name;
	List<Branch*> branches;

	bool idExists( std::string id ) const noexcept;
public:
	class BankError final: std::invalid_argument
	{
	public:
		using std::invalid_argument::invalid_argument;
		using std::invalid_argument::what;
	};

	Bank() = delete;
	Bank( std::string name ): name( name ), branches() {};
	~Bank();

	Bank( const Bank& src ) = delete;
	Bank( Bank&& src ) = default;

	Bank& operator=( const Bank& rhs ) = delete;
	Bank& operator=( Bank&& rhs ) = default;

	void newBranch( std::string branchID );
	void newBranch( std::string branchID, Address address );

	Branch& getBranch( std::string branchID ) const;
	const List<Branch*>& getBranches() const noexcept { return branches; };

	void removeBranch( std::string branchID );

	std::string getName() const noexcept { return name; };
};


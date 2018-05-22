#pragma once

#include <string>
#include <stdexcept>
#include "Bank.h"
#include "Address.h"
#include "Account.h"
#include "Employee.h"
#include "Client.h"
#include "../../list/List.h"

class Bank::Branch
{
	const std::string id;
	Address address;
	List<Account*> accounts;
	List<Employee*> employees;
	List<Client*> clients;
public:
	class BranchError final: std::invalid_argument
	{
	public:
		using std::invalid_argument::invalid_argument;
		using std::invalid_argument::what;
	};

	Branch() = delete;
	Branch( std::string id ): id( id ), accounts(), employees(), clients() {};
	Branch( std::string id, Address address ): id( id ), address( address ), accounts(), employees(), clients() {};
	Branch( std::string id,
			std::string nCity, std::string nZip, std::string nStreet, std::string nBuildNo, std::string nFlatNo = std::string() ):
			id( id ), address( nCity, nZip, nStreet, nBuildNo, nFlatNo ), accounts(), employees(), clients() {};

	~Branch();

	Branch( const Branch& src ) = delete;
	Branch( Branch&& src ) = default;
	
	Branch& operator=( const Branch& src ) = delete;
	Branch& operator=( Branch&& src ) = default;

	const Address& getAddress() const noexcept { return address; };
	std::string getID() const noexcept { return id; };

	void newAccount( Client* client, std::string number, double balance = 0 );
	void closeAccount( Account* acc );

	void hire( Employee* emp, double wage, int hours );
	void fire( Employee* emp );

	const List<Account*>& getAccounts() const noexcept { return accounts; };
	const List<Employee*>& getEmployees() const noexcept { return employees; };
	const List<Client*>& getClients() const noexcept { return clients; };
};


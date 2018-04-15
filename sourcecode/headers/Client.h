#pragma once

#include "Person.h"
#include "Account.h"
#include "../templates/List.h"

class Account;

class Client:
	public Person
{
	List<Account*> accounts;
	double totalBalance;
public:
	Client( std::string id ):
		Person( id ), totalBalance( 0 ), accounts() {};
	Client( std::string nName, std::string nSurname, std::string nID, Address nAddress ):
		Person( nName, nSurname, nID, nAddress ), totalBalance( 0 ), accounts() {};
	Client( std::string nName, std::string nSurname, std::string nID,
			std::string nCity, std::string nZip, std::string nStreet, std::string nBuildNo, std::string nFlatNo = std::string() ):
		Person( nName, nSurname, nID, nCity, nZip, nStreet, nBuildNo, nFlatNo ), totalBalance( 0 ), accounts() {};
	~Client();
	void newAccount( Account* acc );
	void closeAccount( Account* acc );
	const List<Account*>& getAccounts() const noexcept { return accounts; };
	double getBalance() const noexcept { return totalBalance; };
	void update() noexcept;
};
#pragma once

#include <string>
#include <vector>
#include "Bank.h"
#include "Address.h"
#include "Service.h"
#include "Employee.h"
#include "Client.h"

class Bank::Branch
{
	const std::string id;
	Address address;
	std::vector<Service*> services;
	std::vector<Employee*> employees;
	std::vector<Client*> clients;
public:
	Branch( std::string id );
	Branch( std::string id, Address address );
	~Branch();
	const Address& getAddress() const noexcept;
	std::string getID() const noexcept;
	void newService( Service* service );
	void closeService( Service* service );
	void hire( Employee* );
	void fire( Employee* );
	const std::vector<Service*> getServices() const noexcept;
	const std::vector<Employee*> getEmployees() const noexcept;
	const std::vector<Client*> getClients() const noexcept;
};


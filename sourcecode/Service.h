#pragma once

#include "Branch.h"
#include "Client.h"

class Service
{
protected:
	const Bank::Branch* branch;
	const Client* client;
public:
	Service( Bank::Branch* br, Client* cl );
	~Service();
	virtual void simulate() = 0;
};


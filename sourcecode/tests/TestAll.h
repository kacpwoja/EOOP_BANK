#pragma once

#include "ErrorLog.h"

#include "list\TestList.h"
#include "bank\Account\TestAccount.h"
#include "bank\Address\TestAddress.h"
#include "bank\Bank\TestBank.h"
#include "bank\Branch\TestBranch.h"
#include "bank\Client\TestClient.h"
#include "bank\Containers\TestContainers.h"
#include "bank\Employee\TestEmployee.h"
#include "bank\Person\TestPerson.h"

namespace tests
{
	void testAll()
	{
		errorlog.log( "Example error log entry" );
		testList::testList();
		testAddress::testAddress();
		testPerson::testPerson();
		testClient::testClient();
		testEmployee::testEmployee();
		testAccount::testAccount();
		testBranch::testBranch();
		testBank::testBank();
		testContainers::testContainers();
	}
}
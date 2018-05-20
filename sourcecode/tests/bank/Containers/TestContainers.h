#pragma once

namespace tests
{
	namespace testContainers
	{
		void testContainers();
		
		namespace testPL
		{
			void testConstructors();
			void testClients();
			void testEmployees();
		}

		namespace testBL
		{
			void testConstructors();
			void testBanks();
		}

	}
}
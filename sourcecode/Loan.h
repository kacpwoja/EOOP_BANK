#pragma once

#include "Service.h"
#include "Account.h"

class Loan:
	public Service
{
	double amount;
	double interestRate;
	int remainingPayments;
	double nextPayment;
public:
	Loan( double amnt, double intRate, double length );
	~Loan();
	virtual void simulate() override;
	void payment( Account* );
	double getAmount() const noexcept;
	double getInterestRate() const noexcept;
	int getRemainingPayments() const noexcept;
	double getNextPayment() const noexcept;
};


#pragma once
#include "Service.h"
class Investment:
	public Service
{
	double amount;
	double interestRate;
	int monthsLeft;
public:
	Investment( double amount, double interestRate );
	~Investment();
	double getAmount() const noexcept;
	double getInterestRate() const noexcept;
	int getMonthsLeft() const noexcept;
	virtual void simulate() override;
};


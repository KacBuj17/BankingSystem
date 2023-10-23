#pragma once
#include "Account.h"

class User : public Account
{
private:
	float m_amountOfMoney;
	int m_id;
public:
	User(string username, string passwrod, float amountOfMoney, int id);

	float Get_amountOfMoney()const;
	int Get_id()const;

	void Deposit();
	void Withdraw();
	void Transfer();
};


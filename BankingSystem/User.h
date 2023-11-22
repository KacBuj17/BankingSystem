#pragma once
#include "Account.h"
#include <vector>

class User : public Account
{
private:
	float m_amountOfMoney;
	int m_id;
public:
	User(string username = "", string passwrod = "", float amountOfMoney = 0.0, int id = 0);

	float Get_amountOfMoney()const;
	int Get_id()const;

	void Set_id(int id);
	void Set_amount_of_money(float amount);
	void Deposit();
	void Withdraw();
	void Transfer(vector<User>& users);

	friend ostream& operator<<(ostream& os, const User& obiekt);
	friend istream& operator>>(istream& is, User& obiekt);
};

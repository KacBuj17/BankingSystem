#include "User.h"
#include <iostream>
using namespace std;

User::User(string username, string passwrod, float amountOfMoney, int id) : m_amountOfMoney(amountOfMoney), m_id(id), Account(username, passwrod) {}


float User::Get_amountOfMoney()const
{
	return m_amountOfMoney;
}

int User::Get_id()const
{
	return m_id;
}

void User::Deposit()
{
	float amount = {};

	cout << "Jaka kwote chcesz wplacic?: ";
	cin >> amount;
	cout << "Wplacanie......" << endl;
	m_amountOfMoney = m_amountOfMoney + amount;
	cout << "Kwota zostala wplacona!" << endl;

}
void User::Withdraw()
{
	float amount = {};

	cout << "Jaka kwote chcesz wyplacic?: ";
	cin >> amount;
	cout << "Wyplacanie......" << endl;
	m_amountOfMoney = m_amountOfMoney - amount;
	cout << "Kwota zostala wyplacona!" << endl;
}
void User::Transfer()
{
	int id = {};
	cout << "Hello there" << endl;
}
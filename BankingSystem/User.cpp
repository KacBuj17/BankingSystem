#include "User.h"
#include <iostream>
#include <vector>
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


void User::Set_id(int id)
{
	m_id = id;
}

void User::Set_amount_of_money(float amount)
{
	m_amountOfMoney = amount;
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

void User::Transfer(vector<User>& users)
{
	int id = {};
	int choice = {};
	float amount = {};
	
	cout << "Lista uzytkownikow w systemie: " << endl;

	for (auto& user : users)
	{
		if (user.Get_id() != m_id)
		{
			cout << "Id: " << user.Get_id() << ", Username: " << user.Get_username() << endl;
		}
	}

	cout << "Podaj id uzytkownika, ktoremu chcesz przelac pieniadze: ";
	cin >> choice;

	if (choice == m_id)
	{
		cout << "Wybor niepoprawny!" << endl;
	}
	else
	{
		cout << "Podaj ilosc pieniedzy jaka chcesz przelac: ";
		cin >> amount;

		for (auto& user : users)
		{
			if (user.Get_id() == choice)
			{
				if (m_amountOfMoney >= amount)
				{
					user.Set_amount_of_money(user.Get_amountOfMoney() + amount);
					m_amountOfMoney = m_amountOfMoney - amount;
					break;
				}
				else
				{
					cout << "Nie masz wystarczajacej ilosci srodkow na koncie!" << endl;
					break;
				}
			}
		}
	}
}


ostream& operator<<(ostream& os, const User& obiekt)
{
	os << obiekt.Get_username() << " " << obiekt.Get_password() << " " << obiekt.Get_amountOfMoney() << " " << obiekt.Get_id();
	return os;
}

istream& operator>>(istream& in, User& obiekt)
{
	string username;
	string password;
	int id{};
	float amount{};

	in >> username >> password >> amount >> id;
	obiekt = User(username, password, amount, id);
	return in;
}
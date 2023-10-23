#pragma once
#include <iostream>
using namespace std;

class Account
{
private:
	string m_username, m_password;
public:
	Account(string username, string password);

	string Get_username()const;
	string Get_password()const;

	void Set_username(string username);
	void Set_password(string passwrod);
};


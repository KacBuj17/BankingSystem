#include "Account.h"

Account::Account(string username, string password) : m_username(username), m_password(password) {}

string Account::Get_username()const
{
	return m_username;
}

string Account::Get_password()const
{
	return m_password;
}

void Account::Set_username(string username)
{
	m_username = username;
}

void Account::Set_password(string password)
{
	m_password = password;
}

#pragma once
#include "User.h"
#include <vector>
#include "AdminAccount.h"

class Menu
{
private:
	vector<User> Users;
	string current_user_username;
	string current_user_password;
	AdminAccount m_admin;
public:
	Menu(string username, string password);

	void Login();
	bool UserLogin();
	bool AdminLogin();
	void ShowMenu();
	void ShowAdminMenu();
};


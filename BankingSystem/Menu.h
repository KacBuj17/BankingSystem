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
	bool running;
public:
	Menu(string username, string password);

	void Login();
	bool UserLogin();
	bool AdminLogin();
	void ShowMenu();
	void ShowAdminMenu();

	void Add_user();
	void Delete_user();
	void Modify_user_username();
	void Modify_user_password();
};


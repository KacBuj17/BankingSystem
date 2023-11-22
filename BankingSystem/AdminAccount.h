#pragma once
#include <iostream>
#include "Account.h"
#include "User.h"
#include <vector>
using namespace std;

class AdminAccount : public Account
{
public:
	AdminAccount(string username = "admin", string password = "admin");

	void Show_users_data(vector<User>& users);
	void Add_user(vector<User>& users);
	void Delete_user(vector<User>& users);
	void Modify_user(vector<User>& users);
	void Modify_user_username(User& user);
	void Modify_user_password(User& user);
};


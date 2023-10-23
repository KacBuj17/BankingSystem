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
};


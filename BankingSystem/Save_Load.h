#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "User.h"
using namespace std;

class Save_Load
{
public:
	static vector<User> Load();
	static void Save(vector<User>& users);
};


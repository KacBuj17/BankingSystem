#include "Save_Load.h"
#include <string>

vector<User> Save_Load::Load()
{
	vector<User> users;
	ifstream plik("Uzytkownicy.txt");

	if (plik.is_open() == true)
	{
		User user;
		while (plik >> user)
		{
			users.push_back(user);
		}
		plik.close();
		return users;
	}
	else
	{
		cout << "Nie udalo sie otworzyc pliku!" << endl;
	}
}

void Save_Load::Save(vector<User>& users)
{
	ofstream plik("Uzytkownicy.txt");

	if (plik.is_open() == true)
	{
		for (auto& user : users)
		{
			plik << user << endl;
		}
		plik.close();
	}
	else
	{
		cout << "Nie udalo sie otworzyc pliku!" << endl;
	}
}
#include "AdminAccount.h"


AdminAccount::AdminAccount(string username, string password) : Account(username, password) {}

void AdminAccount::Show_users_data(vector<User>& users)
{
	if (users.empty() == true)
	{
		cout << "W systemie nie ma zadnych uzytkownikow!" << endl;
	}
	else
	{
		for (auto& user : users)
		{
			cout << "\nId: " << user.Get_id() << " \nNazwa uzytkownika: " << user.Get_username() << " \nHaslo: " << user.Get_password() << " \nStan konta: " << user.Get_amountOfMoney() << "zl\n";
		}
	}
}

void AdminAccount::Add_user(vector<User>& users)
{
	string username, password;
	float amoutOfMoney{};

	cout << "Podaj login dla nowego uzytkownika: ";
	cin >> username;
	cout << "Podaj haslo dla nowego uzytkownika: ";
	cin >> password;
	cout << "Podaj poczatkowy stan konta: ";
	cin >> amoutOfMoney;

	users.push_back(User(username, password, amoutOfMoney, users.size() + 1));
	cout << "Uzytkownik zostal dodany do systemu!" << endl;
}

void AdminAccount::Delete_user(vector<User>& users)
{
	if (users.empty() == true)
	{
		cout << "W systemie nie ma zadnych uzytkownikow!" << endl;
	}
	else
	{
		int id{};
		cout << "Lista aktywnych w systemie uzytkownikow: " << endl;

		for (auto& user : users)
		{
			cout << "Id: " << user.Get_id() << " Login: " << user.Get_username() << endl;
		}

		cout << "Podaj ID uzytkownika ktorego chcesz usunac: ";
		cin >> id;
		users.erase(users.begin() + id - 1);
		cout << "Usuwanie uzytkownika...." << endl;


		for (auto& user : users)
		{
			if (user.Get_id() > id)
			{
				user.Set_id(user.Get_id() - 1);
			}
		}
	}
}

void AdminAccount::Modify_user(vector<User>& users)
{
	if (users.empty() == true)
	{
		cout << "W systemie nie ma zadnych uzytkownikow!" << endl;
	}
	else
	{
		int id{};
		char choice{};

		cout << "Lista aktywnych w systemie uzytkownikow: " << endl;

		for (auto& user : users)
		{
			cout << "Id: " << user.Get_id() << " Login: " << user.Get_username() << endl;
		}

		cout << "Podaj ID uzytkownika ktorego chcesz modyfikowac: ";
		cin >> id;

		cout << "1. Modyfikuj nazwe uzytkownika" << endl;
		cout << "2. Modyfikuj haslo uzytkownika" << endl;
		cin >> choice;

		for (auto& user : users)
		{
			if (user.Get_id() == id)
			{
				switch (choice)
				{
				case '1':
					AdminAccount::Modify_user_username(user);
						break;
				case '2':
					AdminAccount::Modify_user_password(user);
					break;
				default:
					cout << "Wybor nieprawidlowy!" << endl;
					break;
				}
			}
		}
	}
}

void AdminAccount::Modify_user_username(User& user)
{
	string username;
	cout << "Podaj nowa nazwe uzytkownika: ";
	cin >> username;

	user.Set_username(username);
}
void AdminAccount::Modify_user_password(User& user)
{
	string password;
	cout << "Podaj nowa nazwe uzytkownika: ";
	cin >> password;

	user.Set_password(password);
}
#include "Menu.h"
#include <iostream>
#include <vector>
#include "User.h"
#include "AdminAccount.h"
#include "Save_Load.h"
using namespace std;

Menu::Menu(string username, string password)  
{
	m_admin.Set_username(username);
	m_admin.Set_password(password);
	Users = Save_Load<User>::Load("Uzytkownicy");
}

void Menu::Login()
{
	bool running = true;
	while (running)
	{
		char choice = {};
		cout << "\nWitaj w systemie naszego banku!" << endl;
		cout << "Dostepne opcje:" << endl;
		cout << "1.Zaloguj sie na konto uzytkownika" << endl;
		cout << "2.Zaloguj sie na konto administratora" << endl;
		cout << "3.Wyjdz z systemu" << endl;
		cin >> choice;

		switch (choice)
		{
		case '1':
			if (UserLogin() == true)
			{
				Menu::ShowMenu();
			}
			else
			{
				cout << "Podane dane sa nieprawidlowe!" << endl;
			}
			break;
		case '2':
			if (AdminLogin() == true)
			{
				Menu::ShowAdminMenu();
			}
			else
			{
				cout << "Podane dane sa nieprawidlowe!" << endl;
			}
			break;
		case '3':
			cout << "Wychodzenie z systemu..." << endl;
			Save_Load<User>::Save(Users, "Uzytkownicy");
			running = false;
			break;
		default:
			cout << "Wybor nieprawidlowy!" << endl;
			break;
		}
	}
}

void Menu::ShowMenu()
{
	bool run = true;
	while (run)
	{
		char choice = {};
		cout << "\nWitaj w panelu uzytkownika!" << endl;
		cout << "            MENU               " << endl;
		cout << "1. Wplac srodki na konto" << endl;
		cout << "2. Wyplac srodki z konta" << endl;
		cout << "3. Przelej srodki na inne konto" << endl;
		cout << "4. Sprawdz stan konta" << endl;
		cout << "5. Wyloguj sie" << endl;
		cout << "Wybierz interesujaca Cie opcje: ";
		cin >> choice;

		for (auto& user : Users)
		{
			if (user.Get_username() == current_user_username && user.Get_password() == current_user_password)
			{
				switch (choice)
				{
				case '1':
					user.Deposit();
					break;
				case '2':
					user.Withdraw();
					break;
				case '3':
					user.Transfer(Users);
					break;
				case '4':
					cout << user.Get_amountOfMoney() << " zl" << endl;
					break;
				case '5':
					cout << "Wychodzenie do panelu glownego...." << endl;

					current_user_username = {};
					current_user_password = {};
					run = false;
					break;
				default:
					cout << "Wybor nieprawidlowy! Sprobuj ponownie." << endl;
					break;
				}
			}
		}
	}
}

void Menu::ShowAdminMenu()
{
	bool run = true;
	while (run)
	{
		char choice = {};
		cout << "\n         ADMIN MENU               " << endl;
		cout << "1. Dodaj uzytkownika" << endl;
		cout << "2. Usun uzytkownika" << endl;
		cout << "3. Modyfikuj dane uzytkownika" << endl;
		cout << "4. Wyswietl informacje o uzytkownikach" << endl;
		cout << "5. Wyjdz do menu glownego" << endl;
		cout << "Wybierz interesujaca Cie opcje: ";
		cin >> choice;

		switch (choice)
		{
		case '1':
			m_admin.Add_user(Users);
			break;
		case '2':
			m_admin.Delete_user(Users);
			break;
		case '3':
			m_admin.Modify_user(Users);
			break;
		case '4':
			m_admin.Show_users_data(Users);
			break;
		case '5':
			cout << "Wychodzenie do panelu glownego...." << endl;
			run = false;
			break;

		default:
			cout << "Wybor nieprawidlowy! Sprobuj ponownie." << endl;
			break;
		}
	}
}

bool Menu::UserLogin()
{
	string username, password;

	cout << "Podaj login: " << endl;
	cin >> username;
	cout << "Podaj haslo: " << endl;
	cin >> password;

	for (auto& user : Users)
	{
		if (user.Get_username() == username && user.Get_password() == password)
		{
			current_user_username = username;
			current_user_password = password;
			return true;
		}
	}
	return false;
}

bool Menu::AdminLogin()
{
	string username, password;

	cout << "Podaj login: " << endl;
	cin >> username;
	cout << "Podaj haslo: " << endl;
	cin >> password;

	if (m_admin.Get_username() == username && m_admin.Get_password() == password)
	{
		return true;
	}
	else
	{
		return false;
	}
}
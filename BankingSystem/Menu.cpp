#include "Menu.h"
#include <iostream>
#include <vector>
#include "User.h"
#include "AdminAccount.h"
using namespace std;

Menu::Menu(string username, string password)  
{
	m_admin.Set_username(username);
	m_admin.Set_password(password);
	running = true;
}

void Menu::Login()
{
		int choice = {};
		cout << "Witaj w systemie naszego banku!" << endl;
		cout << "Dostepne opcje:" << endl;
		cout << "1.Zaloguj sie na konto uzytkownika" << endl;
		cout << "2.Zaloguj sie na konto administratora" << endl;
		cout << "3.Wyjdz z systemu" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			if (UserLogin() == true)
			{
				Menu::ShowMenu();
			}
			else
			{
				cout << "Podane dane sa nieprawidlowe!" << endl;
				Menu::Login();
			}
			break;
		case 2:
			if (AdminLogin() == true)
			{
				Menu::ShowAdminMenu();
			}
			else
			{
				cout << "Podane dane sa nieprawidlowe!" << endl;
				Menu::Login();
			}
			break;
		case 3:
			cout << "Wychodzenie z systemu..." << endl;
			break;
		default:
			cout << "Wybor nieprawidlowy!" << endl;
			Menu::Login();
			break;
		}
}

bool Menu::UserLogin()
{
	string username, password;

	cout << "Podaj login: " << endl;
	cin >> username;
	cout << "Podaj haslo: " << endl;
	cin >> password;

	for (User user : Users)
	{
		if (user.Get_username() == username && user.Get_password() == password)
		{
			current_user_username = username;
			current_user_password = password;
			return true;
		}
		else
		{
			return false;
		}
	}
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

void Menu::ShowMenu()
{
		int choice = {};
		cout << "Witaj w panelu uzytkownika!" << endl;
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
			switch (choice)
			{
			case 1:
				user.Deposit();
				break;
			case 2:
				user.Withdraw();
				break;
			case 3:

				break;
			case 4:
				cout << user.Get_amountOfMoney() << " zl" << endl;
				break;
			case 5:
				cout << "Wychodzenie do panelu glownego...." << endl;
				break;
			default:
				cout << "Wybor nieprawidlowy! Sprobuj ponownie." << endl;
				Menu::ShowMenu();
				break;
			}
		}
}

void Menu::ShowAdminMenu()
{
	int choice = {};
	cout << "         ADMIN MENU               " << endl;
	cout << "1. Dodaj uzytkownika" << endl;
	cout << "2. Usun uzytkownika" << endl;
	cout << "3. Modyfikuj dane uzytkownika" << endl;
	cout << "4. Wyjdz do menu glownego" << endl;
	cout << "Wybierz interesujaca Cie opcje: ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		Add_user();
		break;
	case 2:

		break;
	case 3:

		break;
	case 4:
		cout << "Wychodzenie do panelu glownego...." << endl;
		break;

	default:
		cout << "Wybor nieprawidlowy! Sprobuj ponownie." << endl;
		Menu::ShowAdminMenu();
		break;
	}
}


void Menu::Add_user()
{
	string username, password;
	float amoutOfMoney{};

	cout << "Podaj login dla nowego uzytkownika: ";
	cin >> username;
	cout << "Podaj haslo dla nowego uzytkownika: ";
	cin >> password;
	cout << "Podaj poczatkowy stan konta: ";
	cin >> amoutOfMoney;

	Users.push_back(User(username, password, amoutOfMoney, Users.size() + 1));
	cout << "Uzytkownik zostal dodany do systemu!" << endl;
	ShowAdminMenu();

}
void Menu::Delete_user()
{

}
void Menu::Modify_user_username()
{

}
void Menu::Modify_user_password()
{

}



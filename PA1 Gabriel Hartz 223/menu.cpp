#include "menu.h"

int Menu::draw_menu()
{
	int choice;
	do
	{
		cout << "Please select an option listed below:" << endl;
		cout << "1.Game Rules\n" << "2.Play Game\n" << "3.Load Previous Game\n" << "4.Add Command\n" << "5.Remove Command\n" << "6.Exit" << endl;
		cout << "---->";
		
		cin >> choice;

		//Error checking for user input
		if (choice < 1 || choice > 6)
		{
			//system("cls");
			cout << "Your choice of option is invalid, try again.";
			//system("pause");
		}

	} while (choice < 1 || choice > 6);
	
	return choice;
}
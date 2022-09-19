#include "profileArray.h"

//constructor
ProfilesList::ProfilesList()//imports the players from the file
{
	fstream infile;
	infile.open("profiles.csv");
	Player temp;
	while (infile >> temp)
	{
		this->insertAtFront(temp);
	}

}
void ProfilesList::insertAtFront(Player newProfile)
{
	//shifting elements to the right and then appending the Player in the new spot
	int i;
	Player temp;
	temp = this->list[100 - 1];
	if (this->searchPlayer(newProfile) == false) //checks if the player is already registered in the system
	{
		for (i = 100 - 1; i > 0; i--)
		{
			this->list[i] = this->list[i - 1];
		}
		this->list[0] = newProfile;
	}
	
}
//searchProfile is used by the Option 3 of the game, it checks if the player is already listed and prints his/her score
void ProfilesList::searchProfile()
{

	int i;
	string playerName;
	cout << "Type the name of the profile that you want to see: ";
	cin.ignore();
	bool playerFound = false;
	getline(cin, playerName);
	for (i = 0; i < 100 - 1; i++)
	{
		if (this->list[i].get_name() == playerName)
		{
			system("cls");
			cout << this->list[i].get_name() << " score is: " << this->list[i].get_score() << endl;
			system("pause");
			playerFound = true;
			
		}

	}
	if (playerFound == false)
	{
		system("cls");
		cout << "The player could not be found." << endl;
		system("pause");
	}
	
}
//searchPlayer is used by insert at front to check if the player is already listed
bool ProfilesList::searchPlayer(Player newProfile) 
{
	int i;
	for (i = 0; i < 100 - 1; i++)
	{
		if (this->list[i].get_name() == newProfile.get_name())
		{
			this->list[i] = newProfile;
			return true;
		}

	}
	return false;
}
void ProfilesList::exportList()
{
	int i;
	fstream outfile;
	outfile.open("profiles.csv", std::ofstream::out | std::ofstream::trunc);
	for (i = 0; i < 100 - 1; i++)
	{
		outfile << this->list[i];
	}
	outfile.close();
}
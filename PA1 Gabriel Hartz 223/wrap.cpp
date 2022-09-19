#include "wrap.h"

void Wrap::initialize()
{
	srand(time(NULL));
	this->importcommandList();
	int choosen_option = 0;


	while (choosen_option != 6)
	{
		choosen_option = this->UI.draw_menu();

		if (choosen_option == 1) //rules
		{
			system("cls");
			cout << "The rules for the game are simple, first you are going to choose a number between 5 and 30 rounds of questions. After that, the game is going to give you a command-line, and 3 different descriptions. One of the descriptions is going to match the given command-line, if the player gives the right answer he/she is going to gain 1 point, if the player gives the wrong answer he/she is going to lose 1 point." << endl;
			system("pause");
			system("cls");
		}
		if (choosen_option == 2) //play game
		{
			cin.ignore();
			this->playGame();
		}
		if (choosen_option == 3)
		{
			this->playerList.searchProfile(); //addition for option 3, I could probably have transformed play game into a function, but I don't have much time and the program is working as intended.
			this->playGame();
		}
		if (choosen_option == 4)//add command
		{
			string newCommand;
			string newDescription;
			cin.ignore();
			do {
				system("cls");
				cout << "Type your new command: ";
				getline(cin, newCommand);
				if (this->commandList.searchCommand(newCommand))
				{
					system("cls");
					cout << "The command that you typed already exists, try again.\n";
					system("pause");
				}
			} while (this->commandList.searchCommand(newCommand));
			cout << "Type your command's description: ";
			getline(cin, newDescription);
			newDescription = ('"' + newDescription + '"');

			this->commandList.insert(newCommand, newDescription);
		}
		if (choosen_option == 5)//delete command
		{
			string command;
			cin.ignore();
			do {
				system("cls");
				cout << "Type the name of the command that you wish to remove: ";
				getline(cin, command);
				if (!this->commandList.searchCommand(command))
				{
					system("cls");
					cout << "The command that you typed doesn't match with any command in the list, try again.\n";
					system("pause");
				}
			} while (!this->commandList.searchCommand(command));
			this->commandList.deleteNode(command);
		}
	}
	this->exportcommandList();
	this->playerList.exportList();
}
void Wrap::importcommandList()
{
	string tempCommand;
	string tempDescription;
	fstream infile;
	infile.open("commands.csv");

	while (!infile.eof())
	{
		getline(infile, tempCommand, ',');
		getline(infile, tempDescription, '\n');
		this->commandList.insert(tempCommand, tempDescription);	
	}
	infile.close();
}
void Wrap::exportcommandList()
{
	fstream outfile;
	outfile.open("commands.csv", std::ofstream::out | std::ofstream::trunc);

	this->commandList.printList(outfile);
	this->commandList.deleteList(); //Free's the space used by the list at the end of the program
	outfile.close();


}
void Wrap::playGame()
{
	string playerName;
	Player newPlayer;
	int questionNumber;
	int score = 0;

	//cin.ignore();
	system("cls");
	cout << "Type your name: ";
	getline(cin, playerName);
	newPlayer.set_name(playerName);
	do   //do-while loop implemented to make sure that the number of questions is valid (5-30)
	{
		cout << "\nBetween (5) and (30) questions how many do you want? ";
		cin >> questionNumber;
		if (questionNumber < 5 || questionNumber > 30)
		{
			system("cls");
			cout << "Your choosen number of questions is not valid, try again.\n";
			system("pause");
		}
	} while (questionNumber < 5 || questionNumber > 30);

	string randomCommand, correctDescription, wrongDescription1, wrongDescription2;
	bool commandAlreadyUsed;

	//Vector with the commands that were already used in the game
	vector<string> usedCommands;
	usedCommands.resize(questionNumber);
	while (questionNumber > 0)
	{
		//do-while loop implemented to make sure that the 3 descriptions are different from each other
		do {
			commandAlreadyUsed = false;
			this->commandList.randomizeCommand(randomCommand, wrongDescription1);
			this->commandList.randomizeCommand(randomCommand, wrongDescription2);
			this->commandList.randomizeCommand(randomCommand, correctDescription);
			int i = 0;


			//checks if the generated command was already used in previous turns
			while (i < usedCommands.size())
			{
				if (usedCommands[i] == randomCommand)
				{
					commandAlreadyUsed = true;
					break;
				}
				i++;
			}
		} while ((wrongDescription1 == wrongDescription2) || (wrongDescription1 == correctDescription) || (wrongDescription2 == correctDescription) || (commandAlreadyUsed == true));

		//Vector of descriptions made to randomize the way that the descriptions are displayed
		vector<string> roundDescriptions;
		roundDescriptions.resize(3);

		int randomIndex1 = rand() % 3 + 0;

		roundDescriptions[randomIndex1] = wrongDescription1;
		int randomIndex2;

		do {
			randomIndex2 = rand() % 3 + 0;
		} while (randomIndex1 == randomIndex2);
		roundDescriptions[randomIndex2] = correctDescription;

		int randomIndex3;
		do {
			randomIndex3 = rand() % 3 + 0;
		} while (randomIndex3 == randomIndex1 || randomIndex3 == randomIndex2);
		roundDescriptions[randomIndex3] = wrongDescription2;

		//Now the elements in the vector are printed
		system("cls");
		cout << "Command: " << randomCommand << endl;
		cout << "Description (1):" << roundDescriptions.at(0) << '\n';
		cout << "Description (2):" << roundDescriptions.at(1) << '\n';
		cout << "Description (3):" << roundDescriptions.at(2) << '\n';
		cout << "Type the answer: ";
		int playerAnswer;
		cin >> playerAnswer;
		playerAnswer -= 1;

		if (roundDescriptions[playerAnswer] == correctDescription) //The player selected the right answer
		{
			cout << "Correct! " << correctDescription << endl;
			score += 1;
			cout << "Your current score is: " << score << endl;
			system("pause");
		}
		else //The player selected the wrong answer
		{
			cout << " Incorrect! " << correctDescription << endl;
			score -= 1;
			cout << "Your current score is: " << score << endl;
			system("pause");
		}

		usedCommands[questionNumber - 1] = randomCommand;
		questionNumber -= 1;
	}
	newPlayer.set_score(score);
	this->playerList.insertAtFront(newPlayer);
}

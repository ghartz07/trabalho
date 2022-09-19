#pragma once
#include <vector>
#include "menu.h"
#include "profileArray.h"
#include "linked_list.h"

using std::fstream;
using std::vector;
using std::cin;

class Wrap
{
public:
	void initialize(); //Initializes the program
private:
	Menu UI;
	Linkedlist<string> commandList;
	ProfilesList playerList;
	void importcommandList(); //Populates the linked list with the commands in commands.csv
	void exportcommandList(); //Populates the commands.csv with the commands in the Linked list
	void playGame();
};
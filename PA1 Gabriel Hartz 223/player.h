#pragma once
#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::cin;

class Player
{
public:
	Player(string name = "---", int score = 0);
	void set_name(string newname);
	void set_score(int newscore);

	string get_name();
	int get_score();
private:
	string name;
	int score;
};

fstream& operator<< (fstream& lhs, Player &rhs);
fstream& operator>> (fstream& lhs, Player &rhs);
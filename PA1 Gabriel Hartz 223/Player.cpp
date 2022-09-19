#include "player.h"

//constructor
Player::Player(string newname, int newscore)
{
	this->name = newname;
	this->score = newscore;
}

//setters
void Player::set_name(string newname)
{
	this->name = newname;
}
void Player::set_score(int newscore)
{
	this->score = newscore;
}

//getters
string Player::get_name()
{
	return this->name;
}
int Player::get_score()
{
	return this->score;
}

//stream overload operators
fstream& operator<< (fstream& lhs, Player& rhs)
{
	lhs << rhs.get_name();
	lhs << ',';
	lhs << rhs.get_score() << endl;
	return lhs;
}
fstream& operator>> (fstream& lhs, Player& rhs)
{
	char tempLine[100] = "";
;

	lhs.getline(tempLine, 100, ',');
	rhs.set_name(tempLine);

	lhs.getline(tempLine, 100, '\n');
	rhs.set_score(atoi(tempLine));


	return lhs;
}
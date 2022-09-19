#pragma once
#include "player.h"

class ProfilesList
{
public:
	ProfilesList();
	void insertAtFront(Player newProfile);
	void exportList();
	void searchProfile();
private:
	Player list[100];
	bool searchPlayer(Player newProfile);
};


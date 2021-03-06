//Fugas Intermediate Project 
#include <iostream>
#include <ctime>

//------------------------
#include "HeroManager.h"
#include "PlayerManager.h"
#include "GameManager.h"
//------------------------

using namespace std;

int main()
{
	srand(time_t(NULL));

	PlayerManager players;
	HeroManager heroes;
	InitializeUnits(players, heroes);
	GameManager game_manager(players, heroes);
	game_manager.PerformGameSession(players);

	return 0;
}
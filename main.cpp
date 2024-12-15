#include "Game.h"

using namespace std;


int main() {

	Game game;
	game.RandPassword();
	game.DrawMap();
	bool isRunning = true;
	while (isRunning == true) {
		
		game.Interface();
		system("CLS");
		game.DrawMap();
		game.CheckEndGame(isRunning,  game);
		
	}


	return 0;
}
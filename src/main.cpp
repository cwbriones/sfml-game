#include "game.h"

int main(int argc, char** args){

	Game game(800, 600, "My SFML Game", 60.0f);
	game.gameLoop();

	return 0;
}
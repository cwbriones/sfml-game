#include "Game.h"

int main(int argc, char** args){

	Game app(800, 600, "My SFML Game", 60.0f);
	app.gameLoop();

	return 0;
}

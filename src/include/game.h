#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "fpsmanager.h"

class Game {
public:
	Game(int width, int height, char* title, float fps);
	~Game();

	void gameLoop();
	void render();
private:
	sf::RenderWindow window_;
	
	const int width_;
	const int height_;
	const char* title_;
	FPSManager fpsManager_;
};

#endif //GAME_H
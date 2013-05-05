#ifndef GAME_H
#define GAME_H

#include "fpsmanager.h"
#include "state.h"

#include <vector>

#include <SFML/Graphics.hpp>
#include <boost/smart_ptr.hpp>

class Game {
public:
	Game(int width, int height, char* title, float fps);
	~Game();

	void gameLoop();
	void render(); 
    void update();
    
    void enterState(boost::shared_ptr<GameState> newState);
private:
	sf::RenderWindow window_;
	
	const int width_;
	const int height_;
	const char* title_;
	FpsManager fpsManager_;
    boost::shared_ptr<GameState> currentState_;
};

#endif //GAME_H

#ifndef GAME_H
#define GAME_H

#include "fpsmanager.h"
#include "state.h"

#include <string>

#include <SFML/Graphics.hpp>
#include <boost/smart_ptr.hpp>

class Game {
public:
	Game(int width, int height, std::string title, float fps);
	~Game();

	void gameLoop();
	void render(); 
    void renderDebug();
    void update();
    
    void enterState(BasicGameState* newState);

    const int WIDTH;
	const int HEIGHT;

	const std::string TITLE;
private:
	sf::RenderWindow window_;
    sf::Font debugFont_;
    
	FpsManager fpsManager_;
    BasicGameState* currentState_;
};

#endif //GAME_H

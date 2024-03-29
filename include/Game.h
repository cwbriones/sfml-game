#ifndef GAME_H
#define GAME_H

#include "FpsManager.h"
#include "StateManager.h"

#include <SFML/Graphics.hpp>

#include <string>

class Game {
public:
	Game(int width, int height, std::string title, float fps);
	~Game();

	void gameLoop();
	void render(); 
    void renderStats();
    void update(sf::Time delta);

    void cleanup();
    bool closeRequested(sf::Event& ev);

    const int WIDTH;
	const int HEIGHT;

	const std::string TITLE;
private:
	sf::RenderWindow window_;
    sf::Font debugFont_;
    
	FpsManager fpsManager_;
	StateManager stateManager_;

	bool showDebug_;
};

#endif //GAME_H

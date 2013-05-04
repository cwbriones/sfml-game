#include "game.h"
#include "fpsmanager.h"
#include <iostream>

Game::Game(int width, int height, char* title, float fps) : width_(width),
	height_(height), title_(title), fpsManager_(fps) {

	window_.create(sf::VideoMode(width, height), title);
}

Game::~Game(){

}

void Game::gameLoop(){

	sf::Clock clock;
	sf::Time total = sf::milliseconds(0);

	while(window_.isOpen()){
		sf::Time elapsed = clock.restart();
		total += elapsed;

		if (total.asSeconds() > 1.0f){
			total = sf::Time::Zero;
			std::cout << "Second!" << std::endl;
		}
		sf::Event event;

		while (window_.pollEvent(event)){
			if (event.type == sf::Event::Closed){
				window_.close();
			}
		}
		render();
	}
}

void Game::render(){
	window_.clear(sf::Color::Red);
	window_.display();
}
#include "game.h"
#include "fpsmanager.h"
#include "mainmenustate.h"

#include <iostream>

Game::Game(int width, int height, char* title, float fps) : width_(width),
	height_(height), title_(title), fpsManager_(fps) {

	window_.create(sf::VideoMode(width, height), title);
    window_.setFramerateLimit(60);
}

Game::~Game(){}

/*
 * Method gameLoop:
 *  Delegates rendering/updating functionality to the current game state
 *  and updates the fpsManager to correctly manage the time of these updates.
 */
void Game::gameLoop() {
    
    enterState(boost::shared_ptr<GameState>(new MainMenuState()));

	while(window_.isOpen()){
        int missedUpdates = fpsManager_.tick();
    
        // Decouples rendering and logic
        while ( missedUpdates > 0 ){
            missedUpdates--;
            update();
        }

        // Update the framerate manager
		if (fpsManager_.getTotalTime().asSeconds() > 1.0f){

            fpsManager_.reset();
            std::cout << "Framerate: " << fpsManager_.getActualFps() << std::endl;
		}

		sf::Event event;

        // User input/events would occur here
		while ( window_.pollEvent(event) ){
			if ( event.type == sf::Event::Closed ){
				window_.close();
			}
		}
		render();
	}
    std::cout << std::endl;
}

void Game::enterState(boost::shared_ptr<GameState> newState){
    currentState_ = newState;
    currentState_->initialize();
}

void Game::render() {

	window_.clear( sf::Color::Black );

    currentState_->render(&window_);
	window_.display();

    return;
}

void Game::update() {
    currentState_->update();
}

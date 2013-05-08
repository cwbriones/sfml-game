#include "game.h"
#include "fpsmanager.h"
#include "mainmenustate.h"

#include <cstdlib>
#include <sstream>
#include <string>

Game::Game(int width, int height, std::string title, float fps) : WIDTH(width),
	HEIGHT(height), TITLE(title), fpsManager_(fps) {

	window_.create(sf::VideoMode(width, height), title);

    if (!debugFont_.loadFromFile("../res/Arial.ttf")){
        std::cerr << "Error loading debug font." << std::endl;
        exit(1);
    }
    currentState_ = NULL;
}

Game::~Game(){}

/*
 * Method gameLoop:
 *  Delegates rendering/updating functionality to the current game state
 *  and updates the fpsManager to correctly manage the time of these updates.
 */
void Game::gameLoop() {
    
    enterState(new MainMenuState());
    const int MAX_FRAME_SKIPS = 5;
    const int NUM_DELAYS_PER_YIELD = 5;

    sf::Time period = sf::milliseconds(16.666);
    sf::Time oversleepTime = sf::Time::Zero;
    sf::Time sleepTime = sf::Time::Zero;
    sf::Time excess = sf::Time::Zero;

    int numDelays = 0;
    int skips = 0;

    sf::Clock clock;
    clock.restart();

	while(window_.isOpen()){
		sf::Event event;
        // User input/events would occur here
		while ( window_.pollEvent(event) ){
			if ( event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)){
				
                window_.close();
			}
		}
        update();
		render();

        sf::Time elapsed = clock.restart();

        sleepTime = (period - elapsed) - oversleepTime;
        if (sleepTime > sf::Time::Zero){
            sf::sleep(sleepTime);

            oversleepTime = clock.restart() - sleepTime;

        } else {
            excess += sleepTime;
            oversleepTime = sf::Time::Zero;
            if(++numDelays > NUM_DELAYS_PER_YIELD){
                // Let other threads do shit
                // This doesn't actually do anything yet
                // Since the game loop is in the main thread...I think
            }
        }

        skips = 0;
        while (excess > period && skips < MAX_FRAME_SKIPS){
            skips++;
            excess -= period;

            update();
        }
        fpsManager_.tick();
	}
}

void Game::enterState(BasicGameState* newState){
    BasicGameState* oldState = currentState_;
    currentState_ = newState;

    currentState_->initialize();
    delete oldState;
}

void Game::render() {

	window_.clear( sf::Color::Black );
    currentState_->render(&window_);

    renderDebug();
	window_.display();

    return;
}

void Game::renderDebug(){
    std::ostringstream ss;
    ss << "FPS: " << fpsManager_.getActualFps();

    sf::Text text(ss.str(), debugFont_);
    text.setCharacterSize(16);
    text.setColor(sf::Color::White);

    window_.draw(text);
}

void Game::update() {
    currentState_->update();
}

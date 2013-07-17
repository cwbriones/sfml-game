#include "Game.h"
#include "MainMenuState.h"

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>

Game::Game(int width, int height, std::string title, float fps) : WIDTH(width),
	HEIGHT(height), TITLE(title), stateManager_(this) {

	window_.create(sf::VideoMode(width, height), title, !sf::Style::Resize | sf::Style::Close );

        if (!debugFont_.loadFromFile("../res/Arial.ttf")){
        std::cerr << "Error loading debug font." << std::endl;
        exit(1);
    }
    showDebug_ = false;
    stateManager_.toggleUpdates();
}

Game::~Game(){}

/*
 *  Delegates rendering/updating functionality to the current game state
 *  and updates the fpsManager to correctly manage the time of these updates.
 */
void Game::gameLoop() {

    const int MAX_FRAME_SKIPS = 5;
    const int NUM_DELAYS_PER_YIELD = 5;

    sf::Time period = sf::milliseconds(16.666);
    sf::Time oversleepTime = sf::Time::Zero;
    sf::Time sleepTime = sf::Time::Zero;
    sf::Time excess = sf::Time::Zero;
    sf::Time elapsed = period;

    int numDelays = 0;
    int skips = 0;

    stateManager_.clearToState(new MainMenuState());
    sf::Clock clock;

	while( window_.isOpen() ){
		sf::Event event;

        // User input/events
		while ( window_.pollEvent(event) ){

            if ( closeRequested(event) || stateManager_.closeRequested() ){
                if (stateManager_.currentState()->readyForClose()){
                    window_.close();
                }
	        } else {
                // inputSystem_.checkForInputEvents(event);
                activeInputSystem_->dispatchInputEvents(event);
            }
		}
        // Game updates
        update(elapsed);
		render();

        fpsManager_.tick(elapsed);

        // Check how long it took and sleep accordingly.
        elapsed = clock.restart();
        sleepTime = (period - elapsed) - oversleepTime;

        if (sleepTime > sf::Time::Zero){
            sf::sleep(sleepTime);
            sf::Time actualSleep = clock.restart();

            oversleepTime = actualSleep - sleepTime;
            elapsed += actualSleep;

        } else {
            // We slept too long last time
            excess += sleepTime;
            oversleepTime = sf::Time::Zero;

            if(++numDelays > NUM_DELAYS_PER_YIELD){
                // Let other threads do stuff
                // This won't actually do anything yet
            }
        }

        // Updates are lagging, update without drawing
        skips = 0;
        while (excess > period && skips < MAX_FRAME_SKIPS){
            skips++;
            excess -= period;
            update(period);
        }
        fpsManager_.addSkips(skips);
	}
    cleanup();
}

bool Game::closeRequested(sf::Event& event){
    return event.type == sf::Event::Closed ||
        (event.type == sf::Event::KeyPressed && 
            event.key.code == sf::Keyboard::Escape);
}

void Game::setActiveInputSystem(demo::InputSystem* system){
    activeInputSystem_ = system;
}

void Game::cleanup(){

}

void Game::update(sf::Time delta) {
    stateManager_.clean();
    stateManager_.currentState()->update(delta);
}

void Game::render() {
	window_.clear( sf::Color::Black );
    stateManager_.currentState()->render(&window_);

    if (showDebug_){
        renderStats();
    }

	window_.display();

    return;
}

void Game::renderStats(){
    std::ostringstream ss;
    ss << "FPS: " << fpsManager_.getCurrentFps();

    sf::Text text(ss.str(), debugFont_);
    text.setCharacterSize(16);
    text.setColor(sf::Color::White);
    window_.draw(text);

    ss.str("");
    ss << "UPS: " << fpsManager_.getCurrentUps();
    text.setString(ss.str());
    text.setCharacterSize(16);
    text.setColor(sf::Color::White);
    text.setPosition(0, 15);
    window_.draw(text);

    ss.str("");
    ss << "Avg FPS: " << fpsManager_.getAverageFps();
    text.setString(ss.str());
    text.setCharacterSize(16);
    text.setColor(sf::Color::White);
    text.setPosition(0, 30);
    window_.draw(text);
}

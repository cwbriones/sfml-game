#include "GameState.h"
#include "StateManager.h"
#include "GameplayState.h"
#include "MainMenuState.h"

#include <cstdlib>
#include <iostream>

GameplayState::GameplayState() {
    name_ = "Gameplay";
    
    const char* fontPath = "../res/Arial.ttf";
    if(!font_.loadFromFile(fontPath)){
        std::cerr << "Error loading menu font from " << fontPath << std::endl;
    }
    text_.setFont(font_);
    text_.setCharacterSize(12);
    text_.setString("This is where your gameplay would occur.");

    inputContext_.bindKeyEvent("Exit to Menu", 
            sf::Event::KeyPressed, 
            sf::Keyboard::Key::Escape);
}

GameplayState::~GameplayState(){
    while(!entities_.empty()){
        delete entities_.back();
        entities_.pop_back();
    }
}

void GameplayState::checkForInput(sf::Event& ev){
    if (inputContext_.testEvent("Exit to Menu", ev)){
        manager_->clearToState(new MainMenuState());
    }
}

void GameplayState::createEntities(){
    entities_.push_back(factory_.createPlayer(100, 100, 0, 0));
}

void GameplayState::update(sf::Time delta){
    for ( auto entity : entities_ ){
        entity->update(delta.asMilliseconds());
    }
}

void GameplayState::render(sf::RenderTarget* target){
    target->draw(text_);

    for ( auto entity : entities_ ){
        entity->render(*target); // TODO: Fix this. IE make render accept a RenderTarget reference everywhere
    }
}

void GameplayState::onEnter(){
    createEntities();
}

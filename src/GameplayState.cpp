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

    inputContext_.bindKeyEvent("Exit to Menu", 
            sf::Event::KeyPressed, 
            sf::Keyboard::Key::Escape);
    inputContext_.bindKeyEvent("RotateCCW",
            sf::Event::KeyPressed,
            sf::Keyboard::Key::A);
    inputContext_.bindKeyEvent("RotateCW",
            sf::Event::KeyPressed,
            sf::Keyboard::Key::D);
}

GameplayState::~GameplayState(){
    delete player_;

    while(!entities_.empty()){
        delete entities_.back();
        entities_.pop_back();
    }
}

void GameplayState::checkForInput(sf::Event& ev){
    if (inputContext_.testEvent("Exit to Menu", ev)){
        manager_->clearToState(new MainMenuState());
    }
    else if (inputContext_.testEvent("RotateCW", ev)){
        player_->rotate(4.0);
    } 
    else if (inputContext_.testEvent("RotateCCW", ev)){
        player_->rotate(-4.0);
    }
}

void GameplayState::createEntities(){
    player_ = factory_.createPlayer(100, 100, 0, 0);
}

void GameplayState::update(sf::Time delta){
    player_->update(delta.asMilliseconds());
    for ( auto entity : entities_ ){
        entity->update(delta.asMilliseconds());
    }
}

void GameplayState::render(sf::RenderTarget* target){
    player_->render(*target);
    for ( auto entity : entities_ ){
        entity->render(*target); // TODO: Fix this. IE make render accept a RenderTarget reference everywhere
    }
}

void GameplayState::onEnter(){
    createEntities();
}

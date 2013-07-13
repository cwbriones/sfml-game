#include "GameState.h"
#include "StateManager.h"
#include "GameplayState.h"
#include "MainMenuState.h"

#include <cstdlib>
#include <iostream>

GameplayState::GameplayState(){
    name_ = "Gameplay";
    
    const char* fontPath = "../res/Arial.ttf";
    if(!font_.loadFromFile(fontPath)){
        std::cerr << "Error loading menu font from " << fontPath << std::endl;
    }
    text_.setFont(font_);
    text_.setCharacterSize(12);
    text_.setString("This is where your gameplay would occur.");
    
    entities_.push_back(factory_.createPlayer(100, 100, 0, 0));
}

GameplayState::~GameplayState(){
    while(!entities_.empty()){
        delete entities_.back();
        entities_.pop_back();
    }
}

void GameplayState::update(sf::Time delta){
    for ( auto entity : entities_ ){
        entity->update(delta.asMilliseconds());
    }
}

void GameplayState::onKeyPressed(int keycode){

}

void GameplayState::onKeyReleased(int keycode){
    if (keycode == sf::Keyboard::Escape){
        manager_->clearToState(new MainMenuState());
    }
}

void GameplayState::render(sf::RenderTarget* target){
    target->draw(text_);

    for ( auto entity : entities_ ){
        entity->render(*target); // TODO: Fix this. IE make render accept a RenderTarget reference everywhere
    }
}

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

}

void GameplayState::update(sf::Time delta){

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
}

#include "State.h"
#include "StateManager.h"
#include "GameplayState.h"
#include "MainMenuState.h"

#include <cstdlib>
#include <iostream>

GameplayState::GameplayState(){
    id_ = GameState::GAMEPLAY;
}

void GameplayState::onEnter(){
    std::cout << "Entering: Gameplay" << std::endl;
    if(!font_.loadFromFile("../res/Arial.ttf")){
        exit(1);
    }
    text_.setFont(font_);
    text_.setString("This is the game!");
    text_.setCharacterSize(24);
    text_.setColor(sf::Color::Red);
    text_.setStyle(sf::Text::Bold);
    text_.setPosition(50,50);
}

void GameplayState::onExit(){
    std::cout << "Exiting: Gameplay" << std::endl;
}

void GameplayState::onHidden(){}

void GameplayState::onRevealed(){}

void GameplayState::update(sf::Time delta){}

void GameplayState::keyPressed(int keycode){
    if (keycode == sf::Keyboard::Escape) { 
        manager_->clearToState(new MainMenuState());
    }
}

void GameplayState::keyReleased(int keycode){}

void GameplayState::render(sf::RenderTarget* target){
    target->draw(text_);
}

bool GameplayState::readyForClose(){
    return false;
}

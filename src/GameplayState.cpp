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
}

void GameplayState::onExit(){
    std::cout << "Exiting: Gameplay" << std::endl;
}

void GameplayState::onHidden(){}

void GameplayState::onRevealed(){}

void GameplayState::update(sf::Time delta){}

void GameplayState::onKeyPressed(int keycode){

}

void GameplayState::onKeyReleased(int keycode){
    if (keycode == sf::Keyboard::Escape){
        manager_->clearToState(new MainMenuState());
    }
}

void GameplayState::render(sf::RenderTarget* target){
}

bool GameplayState::readyForClose(){
    return false;
}

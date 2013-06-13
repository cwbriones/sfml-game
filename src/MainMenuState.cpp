#include "MainMenuState.h"
#include "GameplayState.h"
#include "StateManager.h"

#include <SFML/Window/Keyboard.hpp>

#include <iostream>
#include <cstdlib>

MainMenuState::MainMenuState() : menu_("../res/Arial.ttf") { 
    id_ = GameState::MAIN_MENU;
}

void MainMenuState::onEnter(){
    std::cout << "Entering: Menu" << std::endl;

    menu_.setPosition(10, 10);
    menu_.setFontSize(20);
    menu_.addItem("Start Game");
    menu_.addItem("Options");
    menu_.addItem("Credits");
    menu_.addItem("Exit");
}

void MainMenuState::onExit(){
    std::cout << "Exiting: Menu" << std::endl;
}

void MainMenuState::onHidden(){}

void MainMenuState::onRevealed(){}

void MainMenuState::onKeyPressed(int keycode){
    if (keycode == sf::Keyboard::Up){
        menu_.decrementSelection();
    } else if (keycode == sf::Keyboard::Down) {
        menu_.incrementSelection();
    } else if (keycode == sf::Keyboard::Return){
        menu_.activateSelection();
    }
}

void MainMenuState::onKeyReleased(int keycode){
}

void MainMenuState::update(sf::Time delta){
    if (menu_.isActive("Start Game")){
        manager_->clearToState(new GameplayState());
    }
}

void MainMenuState::render(sf::RenderTarget* target){
    menu_.render(target);
}

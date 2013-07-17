#include "MainMenuState.h"
#include "GameplayState.h"
#include "CreditsState.h"
#include "StateManager.h"

#include "Menu/Menu.h"

#include <SFML/Window/Keyboard.hpp>

#include <iostream>
#include <cstdlib>

MainMenuState::MainMenuState() : menu_(&inputSystem_, "../res/Arial.ttf") { 
    name_ = "Main Menu";
}

void MainMenuState::onEnter(){
    menu_.setPosition(10, 10);
    menu_.setFontSize(20);

    menu_.addItem("Start Game", [&](){ this->manager_->clearToState(new GameplayState()); });
    menu_.addItem("Options");
    menu_.addItem("Credits", [&](){ this->manager_->pushState(new CreditsState()); });
    menu_.addItem("Exit", [&](){ this->manager_->requestClose(); });
}

void MainMenuState::update(sf::Time delta){
    if (menu_.isActive("Start Game")){
        manager_->clearToState(new GameplayState());
    }
}

void MainMenuState::render(sf::RenderTarget* target){
    menu_.render(target);
}

#include "MainMenuState.h"
#include "GameplayState.h"
#include "CreditsState.h"
#include "StateManager.h"

#include "Menu/Menu.h"

#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <cstdlib>

MainMenuState::MainMenuState() : menu_("../res/Arial.ttf") { 
    name_ = "Main Menu";
}

void MainMenuState::onEnter(){
    menu_.setPosition(10, 10);
    menu_.setFontSize(20);

    menu_.addItem("Start Game", [&](){ this->manager_->clearToState(new GameplayState()); });
    menu_.addItem("Options");
    menu_.addItem("Credits", [&](){ this->manager_->pushState(new CreditsState()); });
    menu_.addItem("Exit", [&](){ this->manager_->requestClose(); });

    inputContext_.bindKeyEvent("Menu Up", sf::Event::KeyPressed, sf::Keyboard::Key::Up);
    inputContext_.bindKeyEvent("Menu Down", sf::Event::KeyPressed, sf::Keyboard::Key::Down);
    inputContext_.bindKeyEvent("Menu Select", sf::Event::KeyPressed, sf::Keyboard::Key::Return);
}

void MainMenuState::update(sf::Time delta){

}

void MainMenuState::render(sf::RenderTarget* target){
    menu_.render(target);
}

void MainMenuState::checkForInput(sf::Event& ev){
    if (inputContext_.testEvent("Menu Up", ev)){
        menu_.decrementSelection();
    }
    else if (inputContext_.testEvent("Menu Down", ev)){
        menu_.incrementSelection();
    }
    else if (inputContext_.testEvent("Menu Select", ev)){ 
        menu_.activateSelection();
    }
}

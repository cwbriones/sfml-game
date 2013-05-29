#include "MainMenuState.h"
#include "GameplayState.h"
#include "StateManager.h"

#include <SFML/Window/Keyboard.hpp>

#include <iostream>
#include <cstdlib>

MainMenuState::MainMenuState(){
    id_ = GameState::MAIN_MENU;
}

void MainMenuState::onEnter(){
    std::cout << "Entering: Menu" << std::endl;
    if(!font_.loadFromFile("../res/Arial.ttf")){
        exit(1);
    }
    text_.setFont(font_);
    text_.setString("This is the main menu!");
    text_.setCharacterSize(24);
    text_.setColor(sf::Color::Red);
    text_.setStyle(sf::Text::Bold);
    text_.setPosition(50,50);
}

void MainMenuState::onExit(){
    std::cout << "Exiting: Menu" << std::endl;
}

void MainMenuState::onHidden(){}

void MainMenuState::onRevealed(){}

void MainMenuState::keyPressed(int keycode){
    if (keycode == sf::Keyboard::Space){
        manager_->clearToState(new GameplayState());
    }
}

void MainMenuState::keyReleased(int keycode){

}

void MainMenuState::update(sf::Time delta){

}

void MainMenuState::render(sf::RenderTarget* target){
    target->draw(text_);
}

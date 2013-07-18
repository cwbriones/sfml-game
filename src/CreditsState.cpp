#include "StateManager.h"
#include "CreditsState.h"

#include <iostream>

CreditsState::CreditsState(){
    name_ = "Credits"; 
    
    const char* fontPath = "../res/Arial.ttf";
    if(!font_.loadFromFile(fontPath)){
        std::cerr << "Error loading menu font from " << fontPath << std::endl;
    }
    text_.setFont(font_);
    text_.setCharacterSize(12);
    text_.setString("A simple SFML demo created by Christian Briones.");
}

void CreditsState::update(sf::Time delta){
}

void CreditsState::render(sf::RenderTarget* target){
    target->draw(text_);
}

void CreditsState::checkForInput(sf::Event& ev){

}

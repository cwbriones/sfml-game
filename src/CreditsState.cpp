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

    inputContext_.bindKeyEvent("Back to Menu", 
            sf::Event::KeyPressed,
            sf::Keyboard::Key::Escape);
}

void CreditsState::update(sf::Time delta){
}

void CreditsState::render(sf::RenderTarget* target){
    target->draw(text_);
}

void CreditsState::checkForInput(sf::Event& ev){
    if (inputContext_.testEvent("Back to Menu", ev)){
        manager_->popState();
    }
}

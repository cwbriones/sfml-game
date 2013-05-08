/*
 * =====================================================================================
 *
 *       Filename:  mainmenustate.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/04/2013 19:48:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Christian Briones (cb), cwbriones@berkeley.edu
 *   Organization:  
 *
 * =====================================================================================
 */

#include "mainmenustate.h"

#include <cstdlib>

void MainMenuState::initialize(){
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

void MainMenuState::update(){
}

void MainMenuState::render(sf::RenderTarget* target){
    target->draw(text_);
}

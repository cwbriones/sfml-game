#include "Menu/Button.h"

#include <string>
Button::Button(std::string label, float x, float y, float width, float height){
    label_ = label;
    active_ = false;
    hasMouse_ = false;

    setPosition(x, y);

    bounds_.x = width;
    bounds_.y = height;
}

void Button::activate(){
    active_ = true;
    onPress_();
}

bool Button::isActive(){
    return active_;
}

bool Button::hasMouse(){
    return hasMouse_;
}

void Button::update(sf::Vector2i mousePosition, bool buttonDown){

    sf::Vector2f position = getPosition();

    if(mousePosition.x >= position.x && 
       mousePosition.x < position.x + bounds_.x && 
       mousePosition.y >= position.y && 
       mousePosition.y < position.y + bounds_.y){
        hasMouse_ = true;
    } else {
        hasMouse_ = false;
    }

    active_ = hasMouse_ && buttonDown;

    return;
}

std::string Button::getLabel(){
    return label_;
}

void Button::setDimensions(float x, float y){
    bounds_.x = x;
    bounds_.y = y;
}

void Button::setAction(std::function<void(void)> action){
    onPress_ = action;
}

sf::Vector2f Button::getDimensions(){
    return bounds_;
}

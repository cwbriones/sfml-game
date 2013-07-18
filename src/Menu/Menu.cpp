#include "Menu/Menu.h"

#include <string>
#include <unordered_map>
#include <iostream>

Menu::Menu(std::string fontPath) {
    if(!font_.loadFromFile(fontPath)){
        std::cerr << "Error loading menu font from " << fontPath << std::endl; 
    }
    text_.setFont(font_);
    text_.setCharacterSize(12);

    selection_ = buttons_.begin();
}

Menu::~Menu(){
    while (!buttons_.empty()){
        delete buttons_.back();
        buttons_.pop_back();
    }
}

void Menu::update(sf::Vector2i mousePosition, bool buttonDown){

    auto buttonIter = buttons_.begin();
    for (; buttonIter != buttons_.end(); buttonIter++){

        (*buttonIter)->update(mousePosition, buttonDown);
        active_[(*buttonIter)->getLabel()] = (*buttonIter)->isActive();

        bool hasMouse = (*buttonIter)->hasMouse();
        hasMouse_[(*buttonIter)->getLabel()] = hasMouse;

        if (hasMouse){
            selection_ = buttonIter;
        }
    }
}

void Menu::addItem(std::string item_){
    addItem(item_, [](){} );
}

void Menu::addItem(std::string item_, std::function<void()> onPress){

    sf::Vector2f position = getPosition();
    position.y += buttons_.size() * fontSize_;

    Button* button = new Button(item_, position.x, position.y, \
            item_.size() * fontSize_, fontSize_ );
    button->setAction(onPress);

    buttons_.push_back(button);
    selection_ = buttons_.begin();
}

bool Menu::hasMouse(std::string item_){
    return hasMouse_[item_];
}

bool Menu::isActive(std::string item_){
    return active_[item_];
}

void Menu::setFontSize(int size){
    fontSize_ = size;
    text_.setCharacterSize(size);

    resize();
}

void Menu::render(sf::RenderTarget* target){
   for(auto& button : buttons_){

       text_.setString(button->getLabel());
       text_.setPosition(button->getPosition());

       target->draw(text_);
   }
   renderSelection(target);
}

void Menu::activateSelection(){
    (*selection_)->activate();
}

void Menu::renderSelection(sf::RenderTarget* target){
    Button* selectedButton = *selection_;

    sf::RectangleShape selectionRectangle;

    selectionRectangle.setPosition(selectedButton->getPosition());
    selectionRectangle.setSize(selectedButton->getDimensions());
    selectionRectangle.setFillColor(sf::Color::Transparent);
    selectionRectangle.setOutlineColor(sf::Color::White);
    selectionRectangle.setOutlineThickness(1);
    target->draw(selectionRectangle);
}

void Menu::incrementSelection(){
    selection_++;
    if (selection_ == buttons_.end()){
        selection_ = buttons_.begin();
    }
}

void Menu::decrementSelection(){
    if (selection_ == buttons_.begin()){
        selection_ += buttons_.size() - 1;
    } else {
        selection_--;
    }
}

void Menu::resize(){
    sf::Vector2f position = getPosition();

    for(auto& button : buttons_){
        button->setPosition(position.x, position.y);
        position.y += fontSize_;

        button->setDimensions(fontSize_ * button->getLabel().size(), fontSize_);
    }
}

#include "InputSystem.h"
#include "Entity.h"

#include <SFML/Window/Event.hpp>

// TODO: Remove input receiving entities once they are destroyed

namespace demo {

InputSystem::InputSystem(){

}

InputSystem::~InputSystem(){
    // Not responsible for deleting components
}

void InputSystem::registerSink(MouseListener* comp){
    comp->setInputSystem(this);
    mouseSinks_.push_back(comp);
}

void InputSystem::registerSink(KeyboardListener* comp){
    comp->setInputSystem(this);
    keyboardSinks_.push_back(comp);
}

bool InputSystem::checkForInputEvents(sf::Event& event){
    // Keyboard Events
    if ( event.type == sf::Event::KeyPressed ){
        return true;
    }
    else if ( event.type == sf::Event::KeyReleased ){
        return true;
    }
    // Mouse Events
    else if ( event.type == sf::Event::MouseMoved ){
        return true;
    }
    else if ( event.type == sf::Event::MouseWheelMoved ){
        return true;
    }
    else if ( event.type == sf::Event::MouseButtonPressed ){
        return true;
    }
    else if ( event.type == sf::Event::MouseButtonReleased ){
        return true;
    }
    else if ( event.type == sf::Event::MouseEntered ){
        return true;
    }
    else if ( event.type == sf::Event::MouseLeft ){
        return true;
    }
    return false;
}

} // namespace demo

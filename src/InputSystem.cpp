#include "InputSystem.h"
#include "Component/Input.h"
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

void InputSystem::deregisterSink(MouseListener* comp){
    mouseSinks_.remove(comp);
}

void InputSystem::deregisterSink(KeyboardListener* comp){
    keyboardSinks_.remove(comp);
}

void InputSystem::registerSink(KeyboardListener* comp){
    comp->setInputSystem(this);
    keyboardSinks_.push_back(comp);
}

bool InputSystem::checkForInputEvents(sf::Event& event){
    // Keyboard Events
    if ( event.type == sf::Event::KeyPressed ){
        for (auto& keyboardSink : keyboardSinks_) {
            keyboardSink->onKeyPressed(event.key);
        }
        return true;
    }
    else if ( event.type == sf::Event::KeyReleased ){
        for (auto& keyboardSink : keyboardSinks_) {
            keyboardSink->onKeyReleased(event.key);
        }
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

#include "InputSystem.h"
#include "Entity.h"

#include <SFML/Window/Event.hpp>

namespace demo {

InputSystem::InputSystem(){

}

InputSystem::~InputSystem(){
    // Not responsible for deleting components
}

void InputSystem::registerSink(InputComponent* component){
    switch(component->getType()){
        case InputComponent::InputType::KEYBOARD:
            component->setInputSystem(this);
            break;
        case InputComponent::InputType::MOUSE:
            component->setInputSystem(this);
            break;
        case InputComponent::InputType::JOYSTICK:
            component->setInputSystem(this);
            break;
        default:
            break;
    }
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

void InputSystem::delegateKeyboardEvent(sf::Event& ev){
    for ( auto keyboardSink : keyboardSinks_) {
    }
}

void InputSystem::delegateMouseEvent(sf::Event& ev){
    for ( auto mouseSink : mouseSinks_ ){
    }
}

} // namespace demo

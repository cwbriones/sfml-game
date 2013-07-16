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
        case InputComponent::InputType::MOUSE:
            component->setInputSystem(this);
            mouseSinks_.push_back(component);
            break;
        case InputComponent::InputType::KEYBOARD:
            component->setInputSystem(this);
            keyboardSinks_.push_back(component);
            break;
        case InputComponent::InputType::JOYSTICK:
            component->setInputSystem(this);
            joystickSinks_.push_back(component);
            break;
        default:
            break;
    }
}

void InputSystem::delegateKeyboardEvent(sf::Event& ev){

}

void InputSystem::delegateJoystickEvent(sf::Event& ev){

}

void InputSystem::delegateMouseEvent(sf::Event& ev){

}

} // namespace demo

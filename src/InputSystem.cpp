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

void InputSystem::delegateKeyboardEvent(sf::Event& ev){
    for ( auto keyboardSink : keyboardSinks_) {
    }
}

void InputSystem::delegateMouseEvent(sf::Event& ev){
    for ( auto mouseSink : mouseSinks_ ){
    }
}

} // namespace demo

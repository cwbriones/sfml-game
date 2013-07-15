#include "InputSystem.h"
#include "Entity.h"

#include <SFML/Window/Event.hpp>

namespace demo {

InputSystem::InputSystem(){

}

InputSystem::~InputSystem(){
    // Not responsible for deleting components
}

void InputSystem::registerComponent(InputComponent* component){
    component->setInputSystem(this);
}

void InputSystem::delegateEvent(sf::Event& ev){

}

void InputSystem::delegateKeyboardEvent(sf::Event& ev){

}

void InputSystem::delegateJoystickEvent(sf::Event& ev){

}

void InputSystem::delegateMouseEvent(sf::Event& ev){

}

} // namespace demo

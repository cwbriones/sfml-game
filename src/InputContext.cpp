#include "InputContext.h"

#include <iostream>
#include <unordered_map>
#include <SFML/Window/Event.hpp>

// TODO: Remove input receiving entities once they are destroyed

namespace demo {

InputContext::InputContext(){

}

InputContext::~InputContext(){

}

bool testEvent(std::string action, sf::Event ev){
    return false;
}

void InputContext::bindKeyEvent(std::string action, sf::Event::EventType type, int keycode){

    InputEvent myEvent;

    myEvent.inputType = Keyboard;
    myEvent.ev.type = type;
    myEvent.ev.key.code = static_cast<sf::Keyboard::Key>(keycode);

    bindings_[action] = myEvent;
}

std::vector<std::string> InputContext::getAvailableActions(){
    std::vector<std::string> actions;

    return actions;
}

} // namespace demo

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

bool InputContext::testEvent(std::string action, sf::Event& ev){

   if (bindings_.find(action) != bindings_.end()){
        InputEvent& myEvent = bindings_.at(action);

        // Keyboard Input
        if (myEvent.inputType == Keyboard &&
            myEvent.ev.type == ev.type &&
            myEvent.ev.key.code == ev.key.code){

            return true;
        }
   }

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

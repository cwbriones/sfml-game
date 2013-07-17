#ifndef DEMO_INPUT_COMPONENT_H
#define DEMO_INPUT_COMPONENT_H

#include <SFML/Window/Event.hpp>
#include "InputSystem.h"

namespace demo {

class Entity;

typedef sf::Event::KeyEvent KeyEvent;
typedef sf::Event::MouseButtonEvent MouseButtonEvent;
typedef sf::Event::MouseWheelEvent MouseWheelEvent;
typedef sf::Event::MouseMoveEvent MouseMoveEvent;

class InputComponent
{
public:
    enum class InputType {
        KEYBOARD,
        MOUSE,
        JOYSTICK,
        UNDEFINED
    };

    virtual ~InputComponent(){};
    virtual void update(Entity& owner, int delta) = 0;

    void setInputSystem(InputSystem* system){
        inputSystem_ = system;
    }
    InputType getType(){ return type_; };
protected:
    InputType type_ = InputType::UNDEFINED;
    InputSystem* inputSystem_ = nullptr;
}; // InputComponent

} // namespace demo

#endif // DEMO_INPUT_COMPONENT_H
